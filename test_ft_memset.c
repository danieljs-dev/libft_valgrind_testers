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
    char valid_test_cases[][20] = {
        "Hello, World!",
        "Sample text.",
        "Another test",
        "   ",
        "", // String vazia
        "Just a test"
    };
    
    size_t valid_lengths[] = {13, 12, 12, 3, 0, 10}; // Comprimentos dos casos de teste
    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-20s %-20s %-20s %-15s\033[0m\n", 
           "Test Case", "ft_memset", "memset", "Match");
    
    for (int i = 0; i < num_valid_tests; i++) {
        char ft_memset_result[20]; // Buffer para a função ft_memset
        char memset_result[20];     // Buffer para a função memset

        // Usando ft_memset e memset
        ft_memset(ft_memset_result, '*', valid_lengths[i]);
        memset(memset_result, '*', valid_lengths[i]);
        ft_memset_result[valid_lengths[i]] = '\0'; // Garantindo a terminação da string
        memset_result[valid_lengths[i]] = '\0';     // Garantindo a terminação da string

        // Verifica se os resultados correspondem
        const char *match = (strcmp(ft_memset_result, memset_result) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

        // Formata a saída
        printf("%-20s \033[1;32m%-20s\033[0m \033[1;36m%-20s\033[0m %s\n", 
               valid_test_cases[i], ft_memset_result, memset_result, match);
    }

	if (only_valid)
	{
		// Testes para parâmetros inválidos
		printf("\n\033[1;34m%-20s %-20s %-20s %-15s\033[0m\n", 
			"Invalid Parameter Tests", "ft_memset", "memset", "Match");

		// Teste com n = 0
		char test_case_n0[20] = "No change";
		ft_memset(test_case_n0, '*', 0);
		char memset_case_n0[20] = "No change"; // memmove não deve alterar
		memset(memset_case_n0, '*', 0);
		const char *match_n0 = (strcmp(test_case_n0, memset_case_n0) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";
		printf("n = 0:       '%s'       '%s'       %s\n", test_case_n0, memset_case_n0, match_n0);

		// Teste com c = 0 (deve preencher com null characters)
		char test_case_0[20] = "Test string";
		ft_memset(test_case_0, 0, 5); // Preenche os primeiros 5 bytes com '\0'
		test_case_0[19] = '\0'; // Garantindo a terminação
		char memset_case_0[20] = "Test string";
		memset(memset_case_0, 0, 5);
		memset_case_0[19] = '\0'; // Garantindo a terminação
		const char *match_case_0 = (strcmp(test_case_0, memset_case_0) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";
		printf("c = 0:       '%s'       '%s'       %s\n", test_case_0, memset_case_0, match_case_0);

		// Teste com c = 255 (deve preencher com o valor máximo)
		char test_case_255[20] = "Test string";
		ft_memset(test_case_255, 255, 5); // Preenche os primeiros 5 bytes com '\xff'
		test_case_255[19] = '\0'; // Garantindo a terminação
		char memset_case_255[20] = "Test string";
		memset(memset_case_255, 255, 5);
		memset_case_255[19] = '\0'; // Garantindo a terminação
		const char *match_case_255 = (strcmp(test_case_255, memset_case_255) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";
		printf("c = 255:     '%s'       '%s'       %s\n", test_case_255, memset_case_255, match_case_255);

		// Teste com n > tamanho do buffer
		char test_case_large[20] = "Test";
		ft_memset(test_case_large, '*', 30); // Comportamento indefinido
		test_case_large[19] = '\0'; // Garantindo a terminação
		char memset_case_large[20] = "Test";
		memset(memset_case_large, '*', 30); // Também comportamento indefinido
		memset_case_large[19] = '\0'; // Garantindo a terminação
		const char *match_case_large = (strcmp(test_case_large, memset_case_large) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";
		printf("n grande:     '%s'       '%s'       %s\n", test_case_large, memset_case_large, match_case_large);
	}

    return 0;
}