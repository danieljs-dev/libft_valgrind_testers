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
    const char *valid_test_cases[][2] = {
        {"Hello, ", "World!"},
        {"Foo", "Bar"},
        {"", "Empty"},
        {"Non-empty", ""},
        {"", ""},
        {"First part ", "Second part"},
        {"123", "456"},
    };

    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-30s %-30s %-30s\033[0m\n", "s1", "s2", "Output");
    printf("\033[1;34m---------------------------------------------------------------\033[0m\n");

    for (int i = 0; i < num_valid_tests; i++) {
        const char *s1 = valid_test_cases[i][0];
        const char *s2 = valid_test_cases[i][1];
        char *result = ft_strjoin(s1, s2);
        
        // Imprimir resultado
        printf("\033[1;36m%-30s %-30s \033[1;32m%-30s\033[0m\n", s1, s2, result ? result : "(NULL)");
        
        free(result); // Liberar memória alocada
    }

    printf("\033[1;34m---------------------------------------------------------------\033[0m\n");
    return 0;
}