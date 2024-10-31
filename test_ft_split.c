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
        "Hello,World",
        "A,B,C,D",
        "split,this,string",
        ",leading,and,trailing,commas,",
        "no,separators,here",
        "   multiple spaces   in   between   ",
        "one char token",
        "a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z",
        "  double  spaces  and  single spaces",
        "",
        "  ",
        "      ",
    };
    
    char sep;
    //sep = ',';
    sep = ' ';
    int num_valid_tests = sizeof(valid_test_cases) / sizeof(valid_test_cases[0]);

    // Cabeçalho formatado
    printf("\033[1;34m%-40s %-40s\033[0m\n", "Test Case", "Split Tokens");

    for (int i = 0; i < num_valid_tests; i++) {
        char **result = ft_split(valid_test_cases[i], sep);
        printf("%-40s", valid_test_cases[i]);
        
        if (result) {
            for (int j = 0; result[j] != NULL; j++) {
                // Exibe os tokens em verde
                printf("\033[1;32m\"%s\"\033[0m", result[j]);
                free(result[j]);
                if (result[j + 1]) {
                    printf(", "); // Adiciona vírgula entre tokens
                }
            }
            free(result);
        } else {
            printf(" \033[1;31mNULL\033[0m"); // Exibe NULL em vermelho
        }
        printf("\n");
    }

    return 0;
}