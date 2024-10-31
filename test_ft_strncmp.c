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
    const struct {
        const char *s1;
        const char *s2;
        size_t n;
    } valid_test_cases[] = {
        {"hello", "hello", 5},
        {"abc", "abc", 3},
        {"abcdef", "abcde", 6},
        {"abcdef", "abcdefg", 6},
        {"abc", "abcd", 3},
        {"abc", "abC", 3}, // Diferentes em maiúsculas
        {"abc", "abc", 0}, // Comparação de comprimento 0
        {"abc", "", 3},    // Comparando com string vazia
        {"", "", 0},       // Ambas vazias
        {"xyz", "xyz", 3},
        {"123", "1234", 3},
        {"abc", "ABC", 3}, // Teste de case sensitivity
    };

    // Casos de teste que devem falhar
    const struct {
        const char *s1;
        const char *s2;
        size_t n;
    } invalid_test_cases[] = {
        {NULL, "test", 4},    // Primeiro parâmetro nulo
        {"test", NULL, 4},    // Segundo parâmetro nulo
        {NULL, NULL, 0},       // Ambos nulos
    };

    // Testando casos válidos
    printf("\033[1;34m%-30s %-30s %-15s %-15s\033[0m\n", 
           "Valid Test Case (s1)", "Valid Test Case (s2)", "ft_strncmp", "strncmp");
    
    for (size_t i = 0; i < sizeof(valid_test_cases) / sizeof(valid_test_cases[0]); i++) {
        int result = ft_strncmp(valid_test_cases[i].s1, valid_test_cases[i].s2, valid_test_cases[i].n);
        int expected = strncmp(valid_test_cases[i].s1, valid_test_cases[i].s2, valid_test_cases[i].n);

        // Verifica se os resultados correspondem
        const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Vermelho para erro

        // Formata a saída
        printf("%-30s %-30s \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", 
               valid_test_cases[i].s1, valid_test_cases[i].s2, result, expected, match);
    }

	if (only_valid)
	{
		// Testando casos inválidos
		printf("\n\033[1;34m%-30s %-30s %-15s %-15s\033[0m\n", 
			"Invalid Test Case (s1)", "Invalid Test Case (s2)", "ft_strncmp", "strncmp");

		for (size_t i = 0; i < sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]); i++) {
			int result = ft_strncmp(invalid_test_cases[i].s1, invalid_test_cases[i].s2, invalid_test_cases[i].n);
			int expected = (invalid_test_cases[i].s1 == NULL || invalid_test_cases[i].s2 == NULL) ? -1 : 0;

			// Para casos inválidos, esperamos que a comparação retorne -1
			const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Vermelho para erro

			// Formata a saída
			printf("%-30s %-30s \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", 
				invalid_test_cases[i].s1 ? invalid_test_cases[i].s1 : "NULL", 
				invalid_test_cases[i].s2 ? invalid_test_cases[i].s2 : "NULL", 
				result, expected, match);
		}
	}

    return 0;
}