#include "./Libft/libft.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	int only_valid = 1;

	if ((argc > 1 && strcmp(argv[1], "valgrind") == 0)) {
        only_valid = 0;
    }
    // Casos de teste válidos
    size_t valid_test_sizes[] = {1, 5, 10, 50}; // Tamanhos para testes válidos
    int num_valid_tests = sizeof(valid_test_sizes) / sizeof(valid_test_sizes[0]);

    printf("\033[1;34m%-15s %-20s %-20s %-15s\033[0m\n", 
           "Size", "ft_bzero", "bzero", "Match");
    
    for (int i = 0; i < num_valid_tests; i++) {
        size_t size = valid_test_sizes[i];
        char *buffer_ft = malloc(size);
        char *buffer_orig = malloc(size);

        // Preenche os buffers com dados não nulos para teste
        memset(buffer_ft, 1, size);
        memset(buffer_orig, 1, size);

        // Chama ambas as funções
        ft_bzero(buffer_ft, size);
        bzero(buffer_orig, size);

        // Verifica se os buffers estão zerados
        int match = 1; // Assume que os buffers são iguais
        for (size_t j = 0; j < size; j++) {
            if (buffer_ft[j] != buffer_orig[j]) {
                match = 0; // Os buffers não são iguais
                break;
            }
        }

        // Formata a saída
        printf("%-15zu \033[1;32m%-20s\033[0m \033[1;36m%-20s\033[0m %s\n", 
               size, 
               (match ? "Passed" : "Failed"),
               (match ? "Passed" : "Failed"),
               (match ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m")); // Indica se houve correspondência

        free(buffer_ft);
        free(buffer_orig);
    }

    return 0;
}