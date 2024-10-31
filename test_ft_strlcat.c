#include "libft.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t strlcat(char *dst, const char *src, size_t size) {
    size_t dst_len = strlen(dst);
    size_t src_len = strlen(src);

    if (size <= dst_len) {
        return size + src_len;
    }

    size_t to_copy = size - dst_len - 1;
    if (to_copy > src_len) {
        to_copy = src_len;
    }

    memcpy(dst + dst_len, src, to_copy);
    dst[dst_len + to_copy] = '\0';

    return dst_len + src_len;
}

int main(int argc, char *argv[]) {
	int only_valid = 1;

	if ((argc > 1 && strcmp(argv[1], "valgrind") == 0)) {
        only_valid = 0;
    }
    const struct {
        char dst[50];
        const char *src;
        size_t size;
    } test_cases[] = {
        {"Hello, ", "World!", 50},
        {"Hello, ", "World!", 10},
        {"", "World!", 50},
        {"Hello, ", "", 50},
        {"", "", 50},
        {"123", "456", 10},
        {"ABCD", "EFGHIJKLMNOP", 20},
        {"123", "456", 5},
        {"Overflow test: ", "This is too long!", 20}
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("\033[1;34m%-30s %-30s %-15s %-15s %-15s\033[0m\n", 
           "Valid Test Case (dst)", "src", "ft_strlcat", "strlcat", "Match");
    printf("\033[1;34m--------------------------------------------------------------------------------\033[0m\n");

    for (int i = 0; i < num_tests; i++) {
        char dst1[50], dst2[50];
        strcpy(dst1, test_cases[i].dst);
        strcpy(dst2, test_cases[i].dst);

        size_t result1 = ft_strlcat(dst1, test_cases[i].src, test_cases[i].size);
        size_t result2 = strlcat(dst2, test_cases[i].src, test_cases[i].size);

        const char *match = (result1 == result2 && strcmp(dst1, dst2) == 0) ? "\033[1;32m✓\033[0m" : "\033[1;31m✗\033[0m";

        printf("\033[1;36m%-30s %-30s \033[1;32m%-15zu\033[0m \033[1;36m%-15zu\033[0m %s\n", 
               test_cases[i].dst, test_cases[i].src, result1, result2, match);
    }

    return 0;
}