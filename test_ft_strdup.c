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
        "Hello, world!", // Teste básico
        "",               // String vazia
        "42",            // Número como string
        "Test string",   // String comum
        "String with spaces", // Espaços no meio
        "Special chars !@#$%^&*", // Caracteres especiais
        "Long string to test allocation", // String longa
    };

    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-30s %-15s %-15s %-15s\033[0m\n", 
           "Valid Test Case", "ft_strdup", "strdup", "Match");
    
    for (int i = 0; i < num_valid_tests; i++) {
        char *expected = strdup(valid_test_cases[i]); // Usando a função original
        char *result = ft_strdup(valid_test_cases[i]); // Usando sua função

        // Verifica se os resultados correspondem
        const char *match = (strcmp(result, expected) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

        // Formata a saída
        printf("%-30s %-15s %-15s %s\n", 
               valid_test_cases[i], result ? result : "NULL", expected ? expected : "NULL", match);
        
        // Libera a memória alocada
        free(expected);
        free(result);
    }

	if (only_valid)
	{
		// Casos de teste que devem ser tratados de forma segura
		const char *invalid_test_cases[] = {
			" ",   // String com espaço
			NULL,  // Ponteiro nulo
		};

		printf("\n\033[1;34m%-30s %-15s %-15s %-15s\033[0m\n", 
			"Invalid Test Case", "ft_strdup", "strdup", "Match");

		for (int i = 0; i < sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]); i++) {
			char *expected = (invalid_test_cases[i] == NULL) ? NULL : strdup(invalid_test_cases[i]);
			char *result = ft_strdup(invalid_test_cases[i]); // Usando sua função

			//const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";
			const char *match = (result == NULL && expected == NULL) || (result && expected && strcmp(result, expected) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

			// Formata a saída
			printf("%-30s %-15s %-15s %s\n", 
				invalid_test_cases[i] ? invalid_test_cases[i] : "NULL", result ? result : "NULL", expected ? expected : "NULL", match);
			
			free(expected); // Liberar memória da string esperada
			free(result);   // Liberar memória da string resultante
		}
	}

    return 0;
}