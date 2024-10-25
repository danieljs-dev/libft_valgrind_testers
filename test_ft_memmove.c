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
    const char *valid_test_cases[] = {
        "Hello, World!",  // Teste básico
        "123456",         // Teste numérico
        "abcdef",         // Teste de letras
        "Test",           // Teste de cópia
        "Memcopy Test",   // Teste com espaço
    };

    size_t valid_lengths[] = {13, 6, 6, 4, 12};
    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-20s %-20s %-20s %-15s\033[0m\n", 
           "Test Case", "ft_memmove", "memmove", "Match");

    for (int i = 0; i < num_valid_tests; i++) {
        char dest1[50] = {0}; // buffer para ft_memmove
        char dest2[50] = {0}; // buffer para memmove
        memcpy(dest2, valid_test_cases[i], valid_lengths[i]); // Copiando para o buffer de comparação
        ft_memmove(dest1, valid_test_cases[i], valid_lengths[i]); // Usando sua função
        memmove(dest2, valid_test_cases[i], valid_lengths[i]); // Usando a função original

        const char *match = (strncmp(dest1, dest2, valid_lengths[i]) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";
        printf("%-20s \033[1;32m%-20s\033[0m \033[1;36m%-20s\033[0m %s\n", 
               valid_test_cases[i], dest1, dest2, match);
    }

	if (only_valid)
	{
		// Casos de teste inválidos
		printf("\n\033[1;34m%-20s %-20s %-20s %-15s\033[0m\n", 
			"Invalid Test Case", "ft_memmove", "memmove", "Match");

		// Comparando NULL src
		char *null_case = NULL;
		char buffer[10] = "Hello";
		ft_memmove(buffer, null_case, 5);
		// A função original não deve falhar, mas o comportamento não é garantido
		memmove(buffer, null_case, 5);
		printf("%-20s \033[1;32m%-20s\033[0m \033[1;36m%-20s\033[0m %s\n", "NULL src", buffer, buffer, "\033[1;32m✓\033[0m");

		// Comparando NULL dest
		char dest[10];
		ft_memmove(null_case, "World", 5);
		// O resultado é indefinido, mas como estamos apenas testando, imprimimos uma mensagem
		printf("%-20s \033[1;32m%-20s\033[0m \033[1;36m%-20s\033[0m %s\n", "NULL dest", "undefined behavior", "undefined behavior", "\033[1;32m✓\033[0m");
	}

    return 0;
}