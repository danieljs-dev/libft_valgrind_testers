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
    // Casos de teste
    int test_cases[] = {
        0,
        42,
        -42,
        2147483647,
        -2147483648,
        123456,
        -123456,
        999999999,
        -999999999,
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("\033[1;34m%-15s %-15s %-15s %-15s\033[0m\n", 
           "Test Case", "ft_itoa", "sprintf", "Match");

    for (int i = 0; i < num_tests; i++) {
        int test_case = test_cases[i];
        
        // Usando sprintf para obter a representação em string
        char expected[12]; // Tamanho suficiente para um inteiro
        sprintf(expected, "%d", test_case);

        char *result = ft_itoa(test_case);  // Usando sua função

        // Verifica se os resultados correspondem
        const char *match = (strcmp(result, expected) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Vermelho para erro

        // Formata a saída
        printf("%-15d \033[1;32m%-15s\033[0m \033[1;36m%-15s\033[0m %s\n", 
               test_case, result, expected, match);

        // Libera a memória
        free(result);
    }

    return 0;
}