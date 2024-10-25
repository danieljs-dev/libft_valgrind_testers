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
        "Hello, world!", // Teste normal
        "abcdefg",       // Teste com letras
        "1234567890",    // Teste com dígitos
        "\0\0\0",        // Teste com caracteres nulos
        "Test string",   // Teste com espaço
    };

    // Caracteres a serem procurados
    int test_chars[] = {
        'H',   // Primeiro caractere
        'e',   // Caractere médio
        '!',   // Último caractere
        'x',   // Caractere que não está na string
        '1',   // Caractere numérico
        '\0'   // Caractere nulo
    };

    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);
    int num_test_chars = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("\033[1;34m%-20s %-15s %-15s %-15s\033[0m\n", 
           "Test String", "ft_memchr", "memchr", "Match");

    for (int i = 0; i < num_valid_tests; i++) {
        for (int j = 0; j < num_test_chars; j++) {
            void *expected = memchr(valid_test_cases[i], test_chars[j], strlen(valid_test_cases[i])); // Usando a função original
            void *result = ft_memchr(valid_test_cases[i], test_chars[j], strlen(valid_test_cases[i])); // Usando sua função

            // Verifica se os resultados correspondem
            const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Vermelho para erro

            // Formata a saída
            printf("%-20s \033[1;32m%-15p\033[0m \033[1;36m%-15p\033[0m %s\n", 
                   valid_test_cases[i], result, expected, match);
        }
    }

    return 0;
}