#include "libft.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static char example_function(unsigned int index, char c) {
    return c + 1; // Apenas incrementa o caractere
}

int main(int argc, char *argv[]) {
	int only_valid = 1;

	if ((argc > 1 && strcmp(argv[1], "valgrind") == 0)) {
        only_valid = 0;
    }
    // Casos de teste válidos
    const char *valid_test_cases[] = {
        "hello",
        "world",
        "abc",
        "ABC",
        "",
        "123",
        "  space  ",
        "C programming"
    };

    // Casos de teste que devem falhar
    const char *invalid_test_cases[] = {
        "this is a long string that should still work", // Teste de limite
        "   ", // Apenas espaços
        NULL // Caso nulo
    };

    // Testando casos válidos
    printf("\033[1;34m%-30s %-30s\033[0m\n", "Valid Test Case", "Result");
    for (int i = 0; i < sizeof(valid_test_cases) / sizeof(valid_test_cases[0]); i++) {
        char *result = ft_strmapi(valid_test_cases[i], example_function);
        
        if (result) {
            printf("%-30s \033[1;32m%-30s\033[0m\n", valid_test_cases[i], result);
            free(result); // Libera a memória alocada
        } else {
            printf("%-30s \033[1;31mNULL\033[0m\n", valid_test_cases[i]);
        }
    }

	if (only_valid)
	{
		// Testando casos inválidos
		printf("\n\033[1;34m%-30s %-30s\033[0m\n", "Invalid Test Case", "Result");
		for (int i = 0; i < sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]); i++) {
			char *result = ft_strmapi(invalid_test_cases[i], example_function);
			
			if (result) {
				printf("%-30s \033[1;32m%-30s\033[0m\n", invalid_test_cases[i], result);
				free(result);
			} else {
				printf("%-30s \033[1;31mNULL\033[0m\n", invalid_test_cases[i]);
			}
		}
	}

    return 0;
}