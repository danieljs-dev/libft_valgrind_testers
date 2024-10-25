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
    char valid_test_cases[] = {'A', 'b', 'C', '1', '!', '\n'};
    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-15s %-15s %-15s %-15s\033[0m\n", 
           "Test Case", "ft_putchar_fd", "Expected Output", "Match");

    // Testes válidos
    for (int i = 0; i < num_valid_tests; i++) {
        // Usando um pipe para capturar a saída
        int pipe_fd[2];
        pipe(pipe_fd);
        
        ft_putchar_fd(valid_test_cases[i], pipe_fd[1]); // Escreve no pipe
        close(pipe_fd[1]); // Fecha o lado de escrita do pipe
        
        char output;
        read(pipe_fd[0], &output, 1); // Lê a saída do pipe
        close(pipe_fd[0]); // Fecha o lado de leitura do pipe
        
        // Verifica se a saída corresponde ao esperado
        const char *match = (output == valid_test_cases[i]) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

        // Formata a saída
        printf("%-15c \033[1;32m%-15c\033[0m \033[1;36m%-15c\033[0m %s\n", 
               valid_test_cases[i], output, valid_test_cases[i], match);
    }

	if (only_valid)
	{
		// Testes inválidos (como caracteres não imprimíveis)
		printf("\n\033[1;34m%-15s %-15s %-15s %-15s\033[0m\n", 
			"Invalid Test Case", "ft_putchar_fd", "Expected", "Match");

		char invalid_test_cases[] = {'\0', 127}; // '\0' e DEL (127)
		int num_invalid_tests = sizeof(invalid_test_cases) / sizeof(invalid_test_cases[0]);

		for (int i = 0; i < num_invalid_tests; i++) {
			// Usando um pipe para capturar a saída
			int pipe_fd[2];
			pipe(pipe_fd);
			
			ft_putchar_fd(invalid_test_cases[i], pipe_fd[1]); // Escreve no pipe
			close(pipe_fd[1]); // Fecha o lado de escrita do pipe
			
			char output;
			read(pipe_fd[0], &output, 1); // Lê a saída do pipe
			close(pipe_fd[0]); // Fecha o lado de leitura do pipe
			
			// Esperamos que o caractere seja escrito, mas pode não ser visível
			const char *match = (output == invalid_test_cases[i]) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

			// Formata a saída
			printf("%-15d \033[1;32m%-15d\033[0m \033[1;36m%-15d\033[0m %s\n", 
				invalid_test_cases[i], output, invalid_test_cases[i], match);
		}
	}

    return 0;
}