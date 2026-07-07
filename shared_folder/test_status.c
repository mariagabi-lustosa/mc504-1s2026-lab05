#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {
    long ret = syscall(477, 5); // Tenta valor 5 (inválido)
    printf("Teste erro (5): %ld, Erro: %d\n", ret, errno);
    
    ret = syscall(477, 1);      // Tenta valor 1 (válido)
    printf("Teste sucesso (1): %ld\n", ret);
    return 0;
}
