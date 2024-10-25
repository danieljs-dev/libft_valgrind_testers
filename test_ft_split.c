#include "./Libft/libft.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static size_t	count_tokens(char const *s, char sep)
{
	size_t		i;
	size_t		tokens;

	i = 0;
	tokens = 0;
	while (s[i])
	{
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			tokens++;
		i++;
	}
	return (tokens);
}

static char	*get_word(const char *s, size_t *index, char sep)
{
	size_t		i;
	size_t		len;
	size_t		start;
	char		*word;

	len = 0;
	while (s[*index] == sep)
		(*index)++;
	start = *index;
	while (s[*index] != sep && s[*index])
	{
		len++;
		(*index)++;
	}
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static char	**free_tokens(char **tokens, size_t count)
{
	size_t		i;

	i = 0;
	while (i < count)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**token_vector;

	if (!s)
		return (NULL);
	token_vector = malloc((count_tokens(s, c) + 1) * sizeof(char *));
	if (token_vector == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		token_vector[j] = get_word(s, &i, c);
		if (!token_vector[j])
			return (free_tokens(token_vector, j));
		j++;
	}
	token_vector[j] = NULL;
	return (token_vector);
}

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