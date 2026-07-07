#include <linux/syscalls.h>
#include <linux/capability.h>

static int kernel_secret;

SYSCALL_DEFINE0(get_secret)
{
    return kernel_secret;
}

SYSCALL_DEFINE1(set_secret, int, val)
{
    if (!capable(CAP_SYS_ADMIN)) // verify the privilege of the calling process
        return -EPERM;

    kernel_secret = val;
    return 0;
}