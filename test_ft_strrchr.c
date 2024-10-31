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
        const char *s;
        int c;
    } valid_test_cases[] = {
        {"hello, world", 'o'},
        {"hello, world", 'l'},
        {"hello, world", 'h'},
        {"hello, world", 'w'},
        {"", 'a'},               // String vazia
        {"abcabc", 'a'},        // Primeiro caractere
        {"abcabc", 'c'},        // Último caractere
        {"abcabc", 'b'},        // Caractere do meio
        {"abcabc", '\0'},       // Caractere nulo
    };

    // Casos de teste que devem falhar
    const struct {
        const char *s;
        int c;
    } invalid_test_cases[] = {
        {"abc", 256}, // Código de caractere fora do range
        {NULL, 'a'}, // String nula
    };

    // Testando casos válidos
    printf("\033[1;34m%-30s %-15s %-15s %-15s\033[0m\n", 
           "Valid Test Case (s)", "ft_strrchr", "strrchr", "Match");

    for (size_t i = 0; i < sizeof(valid_test_cases) / sizeof(valid_test_cases[0]); i++) {
        char *result = ft_strrchr(valid_test_cases[i].s, valid_test_cases[i].c);
        char *expected = strrchr(valid_test_cases[i].s, valid_test_cases[i].c);

        // Verifica se os resultados correspondem
        const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Vermelho para erro

        // Formata a saída
        printf("%-30s %-15s %-15s %s\n", 
               valid_test_cases[i].s, 
               result ? result : "NULL", 
               expected ? expected : "NULL", match);
    }

	if (only_valid)
	{
		// Testando casos inválidos
		printf("\n\033[1;34m%-30s %-15s %-15s %-15s\033[0m\n", 
			"Invalid Test Case (s)", "ft_strrchr", "strrchr", "Match");

		for (size_t i = 0; i < sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]); i++) {
			char *result = ft_strrchr(invalid_test_cases[i].s, invalid_test_cases[i].c);
			char *expected = (invalid_test_cases[i].s == NULL) ? NULL : (char *)0; // Esperado NULL

			// Para casos inválidos, esperamos que a comparação retorne NULL
			const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Vermelho para erro

			// Formata a saída
			printf("%-30s %-15s %-15s %s\n", 
				invalid_test_cases[i].s ? invalid_test_cases[i].s : "NULL", 
				result ? result : "NULL", expected ? expected : "NULL", match);
		}
	}

    return 0;
}