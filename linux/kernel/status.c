#include <linux/syscalls.h>
#include <linux/capability.h>
#include <linux/errno.h> 

//  0: Operacional, 1 :Manutenção, 2: Atualização
static int sistema_status = 0; 

// GET  users podem ler
SYSCALL_DEFINE0(get_status)
{
    return sistema_status;
}

// SET adm pode alterar para 0, 1 ou 2
SYSCALL_DEFINE1(set_status, int, new_status)
{
    // verifica se tem privilégio de adm
    if (!capable(CAP_SYS_ADMIN)) 
        return -EPERM;

    
    // se new_status nn for 0, 1 ou 2, retorna argumento inválido
    if (new_status < 0 || new_status > 2)
        return -EINVAL; 

    sistema_status = new_status;
    return 0;
}