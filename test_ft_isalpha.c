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
        'A',  // Alfabético
        'z',  // Alfabético
        '0',  // Numérico
        '9',  // Numérico
        ' ',  // Não alfabético
        '!',  // Não alfabético
        'a',  // Alfabético
        'Z',  // Alfabético
        '1',  // Numérico
        'b',  // Alfabético
        '\n', // Não alfabético
        '\t', // Não alfabético
    };

    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-15s %-15s %-15s %-15s\033[0m\n", 
           "Test Case", "ft_isalpha", "isalpha", "Match");

    for (int i = 0; i < num_valid_tests; i++) {
        int c = valid_test_cases[i];
        int expected = isalpha(c); // Usando a função original
        int result = ft_isalpha(c); // Usando sua função

        // Verifica se os resultados correspondem
        const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

        // Formata a saída
        printf("%-15c \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", 
               c, result, expected, match);
    }
	if (only_valid)
	{
		// Casos de teste inválidos
		int invalid_test_cases[] = {
			-1,  // Valor inválido
			256, // Valor fora do intervalo de char
			300, // Valor fora do intervalo de char
		};

		int num_invalid_tests = sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]);

		printf("\n\033[1;34m%-15s %-15s %-15s %-15s\033[0m\n", 
			"Test Case", "ft_isalpha", "isalpha", "Match");

		for (int i = 0; i < num_invalid_tests; i++) {
			int c = invalid_test_cases[i];
			int expected = isalpha(c); // Usando a função original
			int result = ft_isalpha(c); // Usando sua função

			// Verifica se os resultados correspondem
			const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

			// Formata a saída
			printf("%-15d \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", 
				c, result, expected, match);
		}
	}

    return 0;
}