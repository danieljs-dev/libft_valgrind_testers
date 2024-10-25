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
        "Hello, World!",
        "Sample text.",
        "Another test",
        "   ",      // String com espaços
        "",         // String vazia
        "Just a test"
    };
    
    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-20s %-20s %-15s\033[0m\n", 
           "Test Case", "ft_putendl_fd", "Expected Output");

    // Testes válidos
    for (int i = 0; i < num_valid_tests; i++) {
        // Usando um pipe para capturar a saída
        int pipe_fd[2];
        pipe(pipe_fd);
        
        ft_putendl_fd((char *)valid_test_cases[i], pipe_fd[1]); // Escreve no pipe
        close(pipe_fd[1]); // Fecha o lado de escrita do pipe
        
        char output[256]; // Buffer para armazenar a saída
        int bytes_read = read(pipe_fd[0], output, sizeof(output) - 1); // Lê a saída do pipe
        close(pipe_fd[0]); // Fecha o lado de leitura do pipe

        output[bytes_read] = '\0'; // Garante a terminação da string

        // Verifica se a saída corresponde ao esperado
        char expected_output[256];
        snprintf(expected_output, sizeof(expected_output), "%s\n", valid_test_cases[i]);

        const char *match = (strcmp(output, expected_output) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

        // Formata a saída
        printf("%-20s \033[1;32m%-20s\033[0m \033[1;36m%-15s\033[0m %s\n", 
               valid_test_cases[i], output, expected_output, match);
    }

	if (only_valid)
	{		
		// Testes inválidos
		printf("\n\033[1;34m%-20s %-20s %-15s\033[0m\n", 
			"Invalid Test Case", "ft_putendl_fd", "Expected Output");

		// Teste com string nula
		printf("NULL string:   (no output expected)\n");
		ft_putendl_fd(NULL, 1); // Não deve produzir saída

		// Teste com fd inválido (0 é considerado inválido neste caso)
		printf("Invalid fd:    (no output expected)\n");
		ft_putendl_fd("Test", 0); // Não deve produzir saída
	}

    return 0;
}