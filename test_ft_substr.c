#include "./Libft/libft.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Definições de cores
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void test_ft_substr() {
    char *result;

    // Teste 1
    result = ft_substr("Hello, World!", 0, 5);
    printf("Test 1: ");
    printf("Result: %s, Expected: Hello, ", result);
    if (strcmp(result, "Hello") == 0) {
        printf(GREEN "Passed" RESET "\n");
    } else {
        printf(RED "Failed" RESET "\n");
    }
    free(result);

    // Teste 2
    result = ft_substr("Hello, World!", 7, 5);
    printf("Test 2: ");
    printf("Result: %s, Expected: World, ", result);
    if (strcmp(result, "World") == 0) {
        printf(GREEN "Passed" RESET "\n");
    } else {
        printf(RED "Failed" RESET "\n");
    }
    free(result);

    // Teste 3
    result = ft_substr("Hello, World!", 0, 13);
    printf("Test 3: ");
    printf("Result: %s, Expected: Hello, World!, ", result);
    if (strcmp(result, "Hello, World!") == 0) {
        printf(GREEN "Passed" RESET "\n");
    } else {
        printf(RED "Failed" RESET "\n");
    }
    free(result);

    // Teste 4
    result = ft_substr("Hello, World!", 5, 10);
    printf("Test 4: ");
    printf("Result: %s, Expected: , World!, ", result);
    if (strcmp(result, ", World!") == 0) {
        printf(GREEN "Passed" RESET "\n");
    } else {
        printf(RED "Failed" RESET "\n");
    }
    free(result);

    // Teste 5
    result = ft_substr("abcdef", 2, 3);
    printf("Test 5: ");
    printf("Result: %s, Expected: cde, ", result);
    if (strcmp(result, "cde") == 0) {
        printf(GREEN "Passed" RESET "\n");
    } else {
        printf(RED "Failed" RESET "\n");
    }
    free(result);

    // Teste 6
    result = ft_substr("abcdef", 4, 10);
    printf("Test 6: ");
    printf("Result: %s, Expected: ef, ", result);
    if (strcmp(result, "ef") == 0) {
        printf(GREEN "Passed" RESET "\n");
    } else {
        printf(RED "Failed" RESET "\n");
    }
    free(result);

    // Teste 7
    result = ft_substr("abcdef", 10, 10);
    printf("Test 7: ");
    printf("Result: %s, Expected: (empty string), ", result);
    if (result == NULL || strcmp(result, "") == 0) {
        printf(GREEN "Passed" RESET "\n");
    } else {
        printf(RED "Failed" RESET "\n");
    }
    free(result);

    // Teste 8
    result = ft_substr(NULL, 0, 10);
    printf("Test 8: ");
    printf("Result: %s, Expected: (NULL), ", result);
    if (result == NULL) {
        printf(GREEN "Passed" RESET "\n");
    } else {
        printf(RED "Failed" RESET "\n");
    }
}

int main(int argc, char *argv[]) {
	int only_valid = 1;

	if ((argc > 1 && strcmp(argv[1], "valgrind") == 0)) {
        only_valid = 0;
    }
    test_ft_substr();
    return 0;
}