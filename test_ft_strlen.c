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
        "Hello, World!",
        "42",
        "",
        "This is a test string.",
        "A",
        "Another test with multiple words.",
        //NULL
    };

    // Casos de teste que devem falhar
    const char *invalid_test_cases[] = {
        "",     // Caso vazio
        NULL  // Caso nulo
    };

    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);
    int num_invalid_tests = sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]);

    printf("\033[1;34m%-30s %-15s %-15s %-15s\033[0m\n", 
           "Valid Test Case", "ft_strlen", "strlen", "Match");
    printf("\033[1;34m--------------------------------------------------------------------------------\033[0m\n");

    for (int i = 0; i < num_valid_tests; i++) {
        size_t expected = strlen(valid_test_cases[i]); // Usando a função original
        size_t result = ft_strlen(valid_test_cases[i]); // Usando sua função

        // Verifica se os resultados correspondem
        const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Verde para igual, vermelho para diferente

        // Formata a saída
        const char *case_str = (valid_test_cases[i] == NULL) ? "NULL" : valid_test_cases[i];
        printf("\033[1;36m%-30s \033[1;32m%-15zu\033[0m \033[1;36m%-15zu\033[0m %s\n", 
               case_str, result, expected, match);
    }

	if (only_valid)
	{
		printf("\n\033[1;34m%-30s %-15s %-15s %-15s\033[0m\n", 
			"Invalid Test Case", "ft_strlen", "strlen", "Match");
		printf("\033[1;34m--------------------------------------------------------------------------------\033[0m\n");

		for (int i = 0; i < num_invalid_tests; i++) {
			size_t expected = 0; // Espera-se que retorne 0 para casos inválidos
			size_t result = ft_strlen(invalid_test_cases[i]); // Usando sua função

			const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Verde para igual, vermelho para diferente

			// Formata a saída
			const char *case_str = (invalid_test_cases[i] == NULL) ? "NULL" : invalid_test_cases[i];
			printf("\033[1;36m%-30s \033[1;32m%-15zu\033[0m \033[1;36m%-15zu\033[0m %s\n", 
				case_str, result, expected, match);
		}
	}

    return 0;
}