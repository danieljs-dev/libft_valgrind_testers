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
    // Casos de teste
    const char test_cases[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
        'U', 'V', 'W', 'X', 'Y', 'Z', // Letras maiúsculas
        'a', 'b', 'c', '1', '!', ' ', // Letras minúsculas, números e caracteres especiais
        '\0' // Caractere nulo
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("\033[1;34m%-5s %-15s %-15s %-15s\033[0m\n", 
           "C", "ft_tolower", "tolower", "Match");

    for (int i = 0; i < num_tests; i++) {
        int c = test_cases[i];
        int expected = tolower(c); // Usando a função original
        int result = ft_tolower(c); // Usando sua função

        // Verifica se os resultados correspondem
        const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Verde para sucesso, vermelho para erro

        // Formata a saída
        printf("%-5c \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", 
               c, result, expected, match);
    }

    return 0;
}