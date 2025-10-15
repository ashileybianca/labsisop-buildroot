#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>

asmlinkage long sys_log_message(const char __user *msg)
{
    char buf[256];
    if (copy_from_user(buf, msg, sizeof(buf) - 1))
        return -EFAULT;

    buf[sizeof(buf) - 1] = '\0';
    printk(KERN_INFO "User message: %s\n", buf);
    return 0;
}