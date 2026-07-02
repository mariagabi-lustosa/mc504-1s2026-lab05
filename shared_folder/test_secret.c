#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#define __NR_get_secret 473
#define __NR_set_secret 474

int main()
{
    int ret;
    int val = 10;

    ret = syscall(__NR_set_secret, val);
    if (ret == -1)
        printf("error on set_secret: %d\n", errno);

    ret = syscall(__NR_get_secret);
    if (ret != val)
        printf("error, expected %d but got %d\n", val, ret);

    return 0;
}
