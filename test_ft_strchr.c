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
        "hello world", // Deve encontrar 'w'
        "42",          // Deve encontrar '4'
        "abcdefg",     // Deve encontrar 'd'
        "testing",     // Deve encontrar 't'
        "string",      // Deve encontrar 's'
        "example",     // Deve encontrar 'e'
        "test null\0", // Deve encontrar '\0'
        "",            // Deve retornar NULL
    };

    // Casos de teste que devem falhar (não encontrar o caractere)
    const char *invalid_test_cases[] = {
        "hello world", // Não deve encontrar 'x'
        "42",          // Não deve encontrar '8'
        "abcdefg",     // Não deve encontrar 'h'
        "testing",     // Não deve encontrar 'z'
        "string",      // Não deve encontrar 'a'
        "test null\0", // Não deve encontrar 'x'
        "string\0more", // Não deve encontrar 'x' (deve retornar '\0')
        NULL          // Caso nulo (deve lidar corretamente)
    };

    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);
    int num_invalid_tests = sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]);

    printf("\033[1;34m%-30s %-15s %-15s %-15s\033[0m\n", 
           "Valid Test Case", "ft_strchr", "strchr", "Match");
    
    for (int i = 0; i < num_valid_tests; i++) {
        char c = (i == 6) ? '\0' : valid_test_cases[i][1]; // Se for o teste de NULL, busca por '\0'
        char *expected = strchr(valid_test_cases[i], c); // Usando a função original
        char *result = ft_strchr(valid_test_cases[i], c); // Usando sua função

        // Verifica se os resultados correspondem
        const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

        // Formata a saída
        printf("%-30s %-15s %-15s %s\n", 
               valid_test_cases[i], result ? result : "NULL", expected ? expected : "NULL", match);
    }

	if (only_valid)
	{
		printf("\n\033[1;34m%-30s %-15s %-15s %-15s\033[0m\n", 
			"Invalid Test Case", "ft_strchr", "strchr", "Match");

		for (int i = 0; i < num_invalid_tests; i++) {
			char c = (i == 7) ? 'a' : 'x'; // 'x' para a maioria dos casos, 'a' para o caso nulo
			char *expected = strchr(invalid_test_cases[i], c); // Usando a função original
			char *result = ft_strchr(invalid_test_cases[i], c); // Usando sua função

			// Verifica se os resultados correspondem
			const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

			// Formata a saída
			printf("%-30s %-15s %-15s %s\n", 
				invalid_test_cases[i] ? invalid_test_cases[i] : "NULL", result ? result : "NULL", expected ? expected : "NULL", match);
		}
	}

    return 0;
}