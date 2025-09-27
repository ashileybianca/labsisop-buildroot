#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/syscalls.h>
#include <linux/rcupdate.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/string.h>

#define CHUNK_SIZE 1024  // tamanho do bloco para copiar incremental

asmlinkage long sys_listSleepingProcesses(char __user *ubuf, size_t usize)
{
    struct task_struct *p;
    char line[128];
    size_t filled = 0;
    int len;

    if (!ubuf) return -EFAULT;
    if (usize == 0) return -EINVAL;

    rcu_read_lock();

    for_each_process(p) {
        long state = READ_ONCE(p->state);
        if (state == TASK_INTERRUPTIBLE || state == TASK_UNINTERRUPTIBLE) {
            char comm[TASK_COMM_LEN];
            get_task_comm(comm, p);

            len = scnprintf(line, sizeof(line), "PID:%d CMD:%s STATE:%ld\n", task_pid_nr(p), comm, state);

            // se a linha couber no buffer do user, copia
            if (filled + len <= usize) {
                if (copy_to_user(ubuf + filled, line, len)) {
                    rcu_read_unlock();
                    return -EFAULT;
                }
                filled += len;
            } else {
                // se não for caber, copia apenas o que couber e encerra
                size_t can_copy = usize - filled;
                if (can_copy > 0)
                    copy_to_user(ubuf + filled, line, can_copy);
                rcu_read_unlock();
                return filled + can_copy;
            }
        }
    }

    rcu_read_unlock();

    return filled;
}
