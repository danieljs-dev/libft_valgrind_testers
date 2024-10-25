# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 14:40:17 by dajesus-          #+#    #+#              #
#    Updated: 2024/10/25 17:03:59 by dajesus-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
CC      = cc
CFLAGS  = -g3

#----------------------------------------------- Colors
CYAN    = \033[0;36m
PURPLE  = \033[0;35m
GREEN   = \033[0;32m
RED     = \033[0;31m
BLUE    = \033[0;34m
YELLOW  = \033[0;33m
RESET   = \033[0m

INCLUDE = -I Libft/libft.h

SRCS    = Libft/ft_bzero.c Libft/ft_isalnum.c Libft/ft_isalpha.c \
           Libft/ft_isascii.c Libft/ft_isdigit.c Libft/ft_isprint.c \
           Libft/ft_memchr.c Libft/ft_memcmp.c Libft/ft_memcpy.c \
           Libft/ft_memmove.c Libft/ft_memset.c Libft/ft_strchr.c \
           Libft/ft_strlen.c Libft/ft_strncmp.c Libft/ft_strrchr.c \
           Libft/ft_toupper.c Libft/ft_tolower.c Libft/ft_strlcpy.c \
           Libft/ft_strlcat.c Libft/ft_strnstr.c Libft/ft_atoi.c \
           Libft/ft_calloc.c Libft/ft_strdup.c Libft/ft_substr.c \
           Libft/ft_strjoin.c Libft/ft_strtrim.c Libft/ft_split.c \
           Libft/ft_itoa.c Libft/ft_strmapi.c Libft/ft_striteri.c \
           Libft/ft_putchar_fd.c Libft/ft_putstr_fd.c Libft/ft_putendl_fd.c \
           Libft/ft_putnbr_fd.c

OBJS    = $(SRCS:Libft/%.c=obj/%.o)

TESTS   = test_ft_bzero.c test_ft_isalnum.c test_ft_isalpha.c test_ft_isascii.c \
           test_ft_isdigit.c test_ft_isprint.c test_ft_memchr.c test_ft_memcmp.c \
           test_ft_memcpy.c test_ft_memmove.c test_ft_memset.c test_ft_strchr.c \
           test_ft_strlen.c test_ft_strncmp.c test_ft_strrchr.c test_ft_toupper.c \
           test_ft_tolower.c test_ft_strlcpy.c test_ft_strlcat.c test_ft_strnstr.c \
           test_ft_atoi.c test_ft_calloc.c test_ft_strdup.c test_ft_substr.c \
           test_ft_strjoin.c test_ft_strtrim.c test_ft_split.c test_ft_itoa.c \
           test_ft_strmapi.c test_ft_striteri.c test_ft_putchar_fd.c test_ft_putstr_fd.c \
           test_ft_putendl_fd.c test_ft_putnbr_fd.c

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $(OBJS)
	@echo "\r\033[K$(GREEN)LIBFT $(BLUE)is ready!$(RESET)"

obj/%.o: Libft/%.c Libft/libft.h
	@mkdir -p obj
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "\r$(CYAN)Compiling $(GREEN)$< $(RESET)"

# Regra para compilar e executar os testes individualmente
test: $(NAME)
	@echo "$(GREEN)Running tests...$(RESET)"
	@for test in $(TESTS); do \
		echo "$(CYAN)Testing function: $$(basename $$test .c)$(RESET)"; \
		$(CC) $(CFLAGS) $(INCLUDE) -o test_program $$test -L. -lft; \
		./test_program \
		echo ""; \
	done

# Regra para testar com Valgrind, gerando log completo
valgrind: $(NAME)
	@echo "$(GREEN)Running Valgrind tests with full log...$(RESET)"
	@for test in $(TESTS); do \
		echo "$(CYAN)Testing function with Valgrind: $$(basename $$test .c)$(RESET)"; \
		$(CC) $(CFLAGS) $(INCLUDE) -o test_program $$test -L. -lft; \
		valgrind -s --leak-check=full --show-leak-kinds=all ./test_program valgrind > /dev/null; \
		echo ""; \
	done

# Regra para testar com Valgrind, filtrando apenas erros e leaks
valgrind_quiet: $(NAME)
	@echo "$(GREEN)Running Valgrind tests filtering errors...$(RESET)"
	@for test in $(TESTS); do \
		echo "$(CYAN)Testing function with Valgrind: $$(basename $$test .c)$(RESET)"; \
		rm -f test_program; \
		$(CC) $(CFLAGS) $(INCLUDE) -o test_program $$test -L. -lft; \
		if [ -f test_program ]; then \
			valgrind -s --leak-check=full --show-leak-kinds=all ./test_program valgrind 2>&1 | grep -E "ERROR SUMMARY|LEAK SUMMARY|definitely lost|indirectly lost" || true; \
		else \
			echo "Failed to create test_program"; \
		fi; \
		echo ""; \
	done

# Regra para limpar objetos e arquivos
clean:
	@echo "$(RED)Removing all .o $(RESET)"
	@rm -rf obj

fclean: clean
	@echo "$(RED)Removing .a$(RESET)"
	@rm -f $(NAME) test_program

re: fclean all

.PHONY: all clean fclean re test valgrind valgrind_errors
