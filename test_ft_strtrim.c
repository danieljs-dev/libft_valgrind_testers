#include "libft.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int only_valid = 1;

    if (argc > 1 && strcmp(argv[1], "valgrind") == 0) {
        only_valid = 0;
    }

    // Casos de teste válidos
    const struct {
        const char *s1;
        const char *set;
    } valid_test_cases[] = {
        {"   Hello, World!   ", " "},
        {"$$$Hello$$$", "$"},
        {"abc", "xyz"},
        {"   ", " "},
        {"", " "},
        {"aabbcc", "abc"},
        {"   Trim me   ", " "},
    };

    // Casos de teste que devem falhar
    const struct {
        const char *s1;
        const char *set;
    } invalid_test_cases[] = {
        {NULL, " "},
        {"Hello", NULL},
        {NULL, NULL},
    };

    // Testando casos válidos
    printf("\033[1;34m%-30s %-15s\033[0m\n", 
           "Valid Test Case (s1)", "ft_strtrim");
    
    for (size_t i = 0; i < sizeof(valid_test_cases) / sizeof(valid_test_cases[0]); i++) {
        char *result = ft_strtrim(valid_test_cases[i].s1, valid_test_cases[i].set);

        // Use um valor esperado diretamente se não tiver uma função de referência
        const char *expected = "expected_value"; // Substitua por um valor correto se necessário
        const char *match = (result && strcmp(result, expected) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

        printf("%-30s %-15s %s\n", 
               valid_test_cases[i].s1, 
               result ? result : "NULL", match);

        free(result); // Libera a memória alocada
    }

    if (only_valid) {
        // Testando casos inválidos
        printf("\n\033[1;34m%-30s %-15s\033[0m\n", 
               "Invalid Test Case (s1)", "ft_strtrim");

        for (size_t i = 0; i < sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]); i++) {
            char *result = ft_strtrim(invalid_test_cases[i].s1, invalid_test_cases[i].set);

            const char *match = (result == NULL) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

            printf("%-30s %-15s %s\n", 
                   invalid_test_cases[i].s1 ? invalid_test_cases[i].s1 : "NULL", 
                   result ? result : "NULL", match);
            
            free(result); // Liberar a memória se não for NULL
        }
    }

    return 0;
}