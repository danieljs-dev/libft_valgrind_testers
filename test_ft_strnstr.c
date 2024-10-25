#include "./Libft/libft.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *strnstr(const char *big, const char *little, size_t len) {
    size_t i;
    size_t j;

    if (little[0] == '\0') return (char *)big;

    for (i = 0; i < len && big[i]; i++) {
        for (j = 0; little[j] == big[i + j] && (i + j) < len; j++) {
            if (little[j + 1] == '\0') return (char *)&big[i];
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
	int only_valid = 1;

	if ((argc > 1 && strcmp(argv[1], "valgrind") == 0)) {
        only_valid = 0;
    }
    // Casos de teste válidos
    const struct {
        const char *big;
        const char *little;
        size_t len;
    } valid_test_cases[] = {
        {"hello, world", "world", 13},
        {"hello, world", "hello", 5},
        {"abcd", "bc", 4},
        {"abcd", "abc", 4},
        {"abcd", "abcd", 4},
        {"abcd", "d", 4},
        {"abcd", "z", 4}, // Não encontrado
        {"abc", "", 3},   // little vazio
        {"", "", 0},      // Ambos vazios
        {"", "a", 0},     // big vazio, little não
    };

    // Casos de teste que devem falhar
    const struct {
        const char *big;
        const char *little;
        size_t len;
    } invalid_test_cases[] = {
        {NULL, "test", 4}, // big nulo
        {"test", NULL, 4}, // little nulo
        {NULL, NULL, 0},    // ambos nulos
    };

    // Testando casos válidos
    printf("\033[1;34m%-30s %-30s %-15s %-15s\033[0m\n", 
           "Valid Test Case (big)", "Valid Test Case (little)", "ft_strnstr", "strnstr");
    
    for (size_t i = 0; i < sizeof(valid_test_cases) / sizeof(valid_test_cases[0]); i++) {
        char *result = ft_strnstr(valid_test_cases[i].big, valid_test_cases[i].little, valid_test_cases[i].len);
        char *expected = strnstr(valid_test_cases[i].big, valid_test_cases[i].little, valid_test_cases[i].len);

        // Verifica se os resultados correspondem
        const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Vermelho para erro

        // Formata a saída
        printf("%-30s %-30s %s \t\t %s %s\n", 
               valid_test_cases[i].big, valid_test_cases[i].little, 
               result ? result : "NULL", expected ? expected : "NULL", match);
    }

	if (only_valid)
	{
		// Testando casos inválidos
		printf("\n\033[1;34m%-30s %-30s %-15s %-15s\033[0m\n", 
			"Invalid Test Case (big)", "Invalid Test Case (little)", "ft_strnstr", "strnstr");

		for (size_t i = 0; i < sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]); i++) {
			char *result = ft_strnstr(invalid_test_cases[i].big, invalid_test_cases[i].little, invalid_test_cases[i].len);
			char *expected = (invalid_test_cases[i].big == NULL || invalid_test_cases[i].little == NULL) ? NULL : (char *)0;

			// Para casos inválidos, esperamos que a comparação retorne NULL
			const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Vermelho para erro

			// Formata a saída
			printf("%-30s %-30s %s \t\t %s %s\n", 
				invalid_test_cases[i].big ? invalid_test_cases[i].big : "NULL", 
				invalid_test_cases[i].little ? invalid_test_cases[i].little : "NULL", 
				result ? result : "NULL", expected ? expected : "NULL", match);
		}
	}

    return 0;
}