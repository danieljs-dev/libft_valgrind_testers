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
    char *valid_test_cases[] = {
        "Hello, World!",
        "Sample text.",
        "Another test",
        "",
        "Just a test"
    };
    
    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    printf("\033[1;34m%-20s %-20s %-15s\033[0m\n", 
           "Test Case", "ft_putstr_fd", "Expected Output");

    // Testes válidos
    for (int i = 0; i < num_valid_tests; i++) {
        int pipe_fd[2];
        pipe(pipe_fd);
        
        ft_putstr_fd(valid_test_cases[i], pipe_fd[1]);
        close(pipe_fd[1]);
        
        char output[256];
        int bytes_read = read(pipe_fd[0], output, sizeof(output) - 1);
        close(pipe_fd[0]);

        output[bytes_read] = '\0';

        const char *match = (strcmp(output, valid_test_cases[i]) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

        printf("%-20s \033[1;32m%-20s\033[0m \033[1;36m%-15s\033[0m %s\n", 
               valid_test_cases[i], output, valid_test_cases[i], match);
    }

	if (only_valid)
	{
		// Testes inválidos
		printf("\n\033[1;34m%-20s %-20s %-15s\033[0m\n", 
			"Invalid Test Case", "ft_putstr_fd", "Expected Output");

		// Teste com s nulo
		printf("Null string:   (no output expected)\n");
		ft_putstr_fd(NULL, 1); // Não deve produzir saída

		// Teste com fd inválido
		printf("Invalid fd:    (no output expected)\n");
		ft_putstr_fd("Test", -1); // Não deve produzir saída
	}

    return 0;
}