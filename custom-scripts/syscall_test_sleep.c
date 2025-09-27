#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

#define SYSCALL_LIST_SLEEPERS 386

int main(void)
{
    size_t size = 64 * 1024;
    char *buf = malloc(size);
    long ret;

    if (!buf) {
        perror("malloc");
        return 1;
    }

    ret = syscall(SYSCALL_LIST_SLEEPERS, buf, size);

    if (ret >= 0) {
        printf("Bytes retornados: %ld\n%s", ret, buf);
    } else {
        printf("Erro na syscall: %ld\n", ret);
    }

    free(buf);
    return (ret < 0);
}
