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
    const char *valid_test_cases[] = {
        "0",
        "42",
        "-42",
        "2147483647",
        "-2147483648",
        "   123",
        "-   123",      // Caso inválido
        "42abc",        // Deve parar em '4'
        "abc42",        // Deve retornar 0
        "   +42",       // Espaços à frente e sinal de mais
        "   -42",       // Espaços à frente e sinal de menos
        "12.34",        // Número com ponto decimal
        "2147483648",   // Fora dos limites
        "-2147483649",  // Fora dos limites
        "2147483647.0", // Número fora dos limites
        "-2147483648.0",// Número fora dos limites
    };

    // Casos de teste que devem falhar
    const char *invalid_test_cases[] = {
        "",                // Caso vazio
        "   ",            // Apenas espaços
        "   -",           // Sinal negativo sem número
        "   +",           // Sinal positivo sem número
        "   --42",        // Sinal duplo
        "   ++42",        // Sinal duplo
        "abc",            // Apenas letras
        "0x1F",           // Número hexadecimal
        "NaN",            // Não é um número
        "Infinity"        // Infinito
    };

    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);
    int num_invalid_tests = sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]);

    printf("\033[1;34m%-30s %-15s %-15s %-15s\033[0m\n", 
           "Valid Test Case", "ft_atoi", "atoi", "Match");
    
    for (int i = 0; i < num_valid_tests; i++) {
        int expected = atoi(valid_test_cases[i]); // Usando a função original
        int result = ft_atoi(valid_test_cases[i]); // Usando sua função

        // Verifica se os resultados correspondem
        const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Vermelho para erro

        // Formata a saída com aspas
        printf("%-30s \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", 
               valid_test_cases[i], result, expected, match);
    }

	if (only_valid)
	{
		printf("\n\033[1;34m%-30s %-15s %-15s %-15s\033[0m\n", 
			"Invalid Test Case", "ft_atoi", "atoi", "Match");

		for (int i = 0; i < num_invalid_tests; i++) {
			//int expected = 0; // Espera-se que falhe ou retorne 0
			int expected = atoi(invalid_test_cases[i]);
			int result = ft_atoi(invalid_test_cases[i]); // Usando sua função

			// Para casos inválidos, esperamos que o resultado seja 0
			const char *match = (result == expected) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m"; // Vermelho para erro

			// Formata a saída
			printf("%-30s \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", 
				invalid_test_cases[i], result, expected, match);
		}
	}

    return 0;
}
