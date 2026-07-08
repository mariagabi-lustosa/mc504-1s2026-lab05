#include <linux/syscalls.h>
#include <linux/printk.h>

// Definindo a syscall que não recebe nenhum argumento
SYSCALL_DEFINE0(good_day)
{
    printk(KERN_INFO "Bom dia!!! =) Que seu dia seu muito divertido!!\n");
    return 0; 
}
