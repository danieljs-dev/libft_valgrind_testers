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
    size_t valid_test_cases[][2] = {
        {0, 0},            // Deve retornar NULL
        {1, 1},            // Deve alocar 1 byte
        {5, 1},            // Deve alocar 5 bytes
        {10, 2},           // Deve alocar 20 bytes
        {50, 2},           // Deve alocar 100 bytes
        {10, 0},           // Deve retornar NULL (tamanho 0)
        {0, 10},           // Deve retornar NULL (tamanho 0)
    };

    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34mVALID TEST CASE\033[0m\n");
    printf("\033[1;34m%-20s %-5s %-9s %-5s\033[0m\n", 
           "nmemb", "ft_calloc", "calloc", "Match");

    for (int i = 0; i < num_valid_tests; i++) {
        size_t nmemb = valid_test_cases[i][0];
        size_t size = valid_test_cases[i][1];

        void *result_ft = ft_calloc(nmemb, size);
        void *result_orig = calloc(nmemb, size);

        // Verifica se ambos os resultados são NULL
        int match = (result_ft == NULL && result_orig == NULL) || 
                    (result_ft != NULL && result_orig != NULL);

        // Formata a saída
        printf("%-20zu %-20s %-20s %-15s\n", 
               nmemb, 
               (result_ft ? "\033[1;32mAllocated\033[0m" : "\033[1;31mNULL\033[0m"),
               (result_orig ? "\033[1;32mAllocated\033[0m" : "\033[1;31mNULL\033[0m"),
               (match ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"));
        
        // Se não forem NULL, podemos comparar o conteúdo
        if (result_ft && result_orig) {
            // Verifica se a memória foi zerada
            int is_zero = 1;
            size_t total_size = nmemb * size; // Total de bytes alocados
            for (size_t j = 0; j < total_size; j++) {
                if (((char *)result_ft)[j] != 0 || ((char *)result_orig)[j] != 0) {
                    is_zero = 0;
                    break;
                }
            }
            printf("%-20s %-20s %-20s %-15s\n", 
                   "Check Zero", 
                   (is_zero ? "\033[1;32mZeroed\033[0m" : "\033[1;31mNot Zeroed"), 
                   (is_zero ? "\033[1;32mZeroed\033[0m" : "\033[1;31mNot Zeroed"),
                   (is_zero ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"));
        }

        // Liberar a memória alocada
        free(result_ft);
        free(result_orig);
    }

	if (only_valid)
	{	
		// Casos de teste inválidos (não devem passar)
		size_t invalid_test_cases[][2] = {
			{0, 1},            // nmemb = 0
			{1, 0},            // size = 0
			{SIZE_MAX, SIZE_MAX}, // nmemb * size > SIZE_MAX,
			{SIZE_MAX, 1},     // Teste de limite (dependendo da alocação do sistema)
		};

		printf("\n\033[1;34mINVALID TEST CASE\033[0m\n");
		printf("\033[1;34m%-20s %-5s %-9s %-5s\033[0m\n", 
			"nmemb", "ft_calloc", "calloc", "Match");

		for (int i = 0; i < sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]); i++) {
			size_t nmemb = invalid_test_cases[i][0];
			size_t size = invalid_test_cases[i][1];
			
			void *result_ft = ft_calloc(nmemb, size);
			void *result_orig = calloc(nmemb, size);

			// Verifica se ambos os resultados são NULL
			int match = (result_ft == NULL && result_orig == NULL) || 
						(result_ft != NULL && result_orig != NULL);

			// Formata a saída
			printf("%-20zu %-20s %-20s %-15s\n", 
				nmemb, 
				(result_ft ? "\033[1;32mAllocated\033[0m" : "\033[1;31mNULL\033[0m"),
				(result_orig ? "\033[1;32mAllocated\033[0m" : "\033[1;31mNULL\033[0m"),
				(match ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"));
		}
	}
    return 0;
}