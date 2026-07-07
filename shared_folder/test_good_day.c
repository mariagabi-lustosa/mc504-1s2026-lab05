#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#define __NR_good_day 475

int main() {
    long ret;
    printf("Calling the Good Day Syscall\n");

    ret = syscall(__NR_good_day);

    if (ret == 0) {
        printf("Sucess - The syscall was called\n");
    } else {
        perror("Error to call the Syscall");
    }

    return 0;
}
