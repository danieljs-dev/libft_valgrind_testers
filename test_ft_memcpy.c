#include "libft.h"

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
        "",               // String vazia
        "Test",           // Teste de cópia
        "Memcopy Test"    // Teste com espaço
    };

    size_t valid_lengths[] = {13, 6, 6, 0, 4, 12};
    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-20s %-20s %-20s %-15s\033[0m\n", 
           "Test Case", "ft_memcpy", "memcpy", "Match");

    for (int i = 0; i < num_valid_tests; i++) {
        char dest1[50] = {0}; // buffer para ft_memcpy
        char dest2[50] = {0}; // buffer para memcpy
        memcpy(dest2, valid_test_cases[i], valid_lengths[i]); // Usando a função original
        ft_memcpy(dest1, valid_test_cases[i], valid_lengths[i]); // Usando sua função

        const char *match = (strncmp(dest1, dest2, valid_lengths[i]) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";
        printf("%-20s \033[1;32m%-20s\033[0m \033[1;36m%-20s\033[0m %s\n", 
               valid_test_cases[i], dest1, dest2, match);
    }

	if (only_valid)
	{
		// Casos de teste inválidos
		printf("\n\033[1;34m%-20s %-20s %-20s %-15s\033[0m\n", 
			"Invalid Test Case", "ft_memcpy", "memcpy", "Match");

		char *null_case = NULL;

		// Comparando NULL src
		char buffer1[10] = {0};
		char buffer2[10] = {0};
		void *result = ft_memcpy(buffer1, null_case, 5);
		void *expected = memcpy(buffer2, null_case, 5); // O comportamento é indefinido
		const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";
		printf("%-20s \033[1;32m%-20p\033[0m \033[1;36m%-20p\033[0m %s\n", "NULL src", result, expected, match);

		// Comparando NULL dest
		result = ft_memcpy(null_case, "Hello", 5);
		expected = memcpy(null_case, "Hello", 5); // O comportamento é indefinido
		match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";
		printf("%-20s \033[1;32m%-20p\033[0m \033[1;36m%-20p\033[0m %s\n", "NULL dest", result, expected, match);
	}

    return 0;
}