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
        '0', // Caractere '0'
        '5', // Caractere '5'
        '9', // Caractere '9'
        'A', // Caractere 'A' (não é dígito)
        'a', // Caractere 'a' (não é dígito)
        ' ', // Espaço (não é dígito)
        48,  // ASCII para '0'
        57,  // ASCII para '9'
    };

    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-15s %-15s %-15s %-15s\033[0m\n", 
           "Test Case", "ft_isdigit", "isdigit", "Match");

    for (int i = 0; i < num_valid_tests; i++) {
        int c = valid_test_cases[i];
        int expected = isdigit(c); // Usando a função original
        int result = ft_isdigit(c); // Usando sua função

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
			-1,  // Fora do intervalo
			128, // Fora do intervalo
			256, // Fora do intervalo
			300, // Fora do intervalo
			'!', // Caracter não numérico
		};

		int num_invalid_tests = sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]);

		printf("\n\033[1;34m%-15s %-15s %-15s %-15s\033[0m\n", 
			"Test Case", "ft_isdigit", "isdigit", "Match");

		for (int i = 0; i < num_invalid_tests; i++) {
			int c = invalid_test_cases[i];
			int expected = isdigit(c); // Usando a função original
			int result = ft_isdigit(c); // Usando sua função

			// Verifica se os resultados correspondem
			const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

			// Formata a saída
			printf("%-15d \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", 
				c, result, expected, match);
		}
	}

    return 0;
}