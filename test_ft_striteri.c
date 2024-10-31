#include "libft.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void print_char(unsigned int index, char *c) {
    printf("\033[1;32mIndex: %u\033[0m, \033[1;34mCharacter: '%c'\033[0m\n", index, *c);
}

int main(int argc, char *argv[]) {
	int only_valid = 1;

	if ((argc > 1 && strcmp(argv[1], "valgrind") == 0)) {
        only_valid = 0;
    }
    // Casos de teste válidos
    const char *valid_test_cases[] = {
        "Hello",
        "World",
        "ft_striteri",
        "Test123",
        "ABC",
        "Special chars: !@#$%^&*()",
        "", // Caso vazio
    };

    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-30s %-15s\033[0m\n", "Valid Test Case", "Output");
    printf("\033[1;34m--------------------------------------------------------\033[0m\n");

    for (int i = 0; i < num_valid_tests; i++) {
        printf("\033[1;36mTesting: \"%s\"\033[0m\n", valid_test_cases[i]);
        // Criar uma cópia da string para não modificar a original
        char *test_case = strdup(valid_test_cases[i]); 
        ft_striteri(test_case, print_char);
        free(test_case); // Liberar memória alocada
        printf("\033[1;34m--------------------------------------------------------\033[0m\n");
    }

    return 0;
}