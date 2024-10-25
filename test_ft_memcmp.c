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
        {"Hello", "Hello"},
        {"Hello", "World"},
        {"abc", "abc"},
        {"abc", "abcd"},
        {"abcd", "abc"},
        {"", ""},
        {"a", ""},
        {"", "a"},
        {"123456", "123456"},
        {"123456", "123457"},
    };

    size_t valid_lengths[] = {5, 5, 3, 3, 4, 0, 1, 1, 6, 6}; 
    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-15s %-15s %-15s %-15s\033[0m\n", 
           "Test Case 1", "ft_memcmp", "memcmp", "Match");

    for (int i = 0; i < num_valid_tests; i++) {
        int expected = memcmp(valid_test_cases[i][0], valid_test_cases[i][1], valid_lengths[i]);
        int result = ft_memcmp(valid_test_cases[i][0], valid_test_cases[i][1], valid_lengths[i]);

        const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";
        printf("%-15s \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", 
               valid_test_cases[i][0], result, expected, match);
    }

	if (only_valid)
	{
		// Casos de teste inválidos
		printf("\n\033[1;34m%-15s %-15s %-15s %-15s\033[0m\n", 
			"Invalid Test Case", "ft_memcmp", "memcmp", "Match");

		const char *str1 = "Hello";
		const char *str2 = "World";

		// Teste com comprimento negativo (não deve ser possível)
		size_t invalid_length = (size_t)-1; // Um valor grande para testar
		int result = ft_memcmp(str1, str2, invalid_length);
		int expected = memcmp(str1, str2, invalid_length);
		const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";
		printf("%-15s \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", "Invalid Length", result, expected, match);

		// Teste comparando strings com tamanho zero
		result = ft_memcmp(str1, str2, 0);
		expected = memcmp(str1, str2, 0);
		match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";
		printf("%-15s \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", "Zero Length", result, expected, match);
	}

    return 0;
}
