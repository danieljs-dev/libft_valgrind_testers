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
    int valid_test_cases[] = {
        0,   // Caracter nulo
        65,  // 'A'
        97,  // 'a'
        48,  // '0'
        127, // DEL (último caractere ASCII)
        32,  // Espaço
        126, // '~'
    };

    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-15s %-15s %-15s %-15s\033[0m\n", 
           "Test Case", "ft_isascii", "isascii", "Match");

    for (int i = 0; i < num_valid_tests; i++) {
        int c = valid_test_cases[i];
        int expected = isascii(c); // Usando a função original
        int result = ft_isascii(c); // Usando sua função

        // Verifica se os resultados correspondem
        const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

        // Formata a saída
        printf("%-15d \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", 
               c, result, expected, match);
    }
	if (only_valid)
	{
		// Casos de teste inválidos
		int invalid_test_cases[] = {
			-1,  // Fora do intervalo ASCII
			128, // Fora do intervalo ASCII
			256, // Fora do intervalo ASCII
			300, // Fora do intervalo ASCII
		};

		int num_invalid_tests = sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]);

		printf("\n\033[1;34m%-15s %-15s %-15s %-15s\033[0m\n", 
			"Test Case", "ft_isascii", "isascii", "Match");

		for (int i = 0; i < num_invalid_tests; i++) {
			int c = invalid_test_cases[i];
			int expected = isascii(c); // Usando a função original
			int result = ft_isascii(c); // Usando sua função

			// Verifica se os resultados correspondem
			const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

			// Formata a saída
			printf("%-15d \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", 
				c, result, expected, match);
		}
	}

    return 0;
}