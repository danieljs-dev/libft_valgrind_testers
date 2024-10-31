CYAN    = \033[0;36m
GREEN   = \033[0;32m
RED     = \033[0;31m
RESET   = \033[0m

define HEADER
                     ___====-_  _-====___
              __--^^^      //     \\     ^^^--_
             _-^         // (    ) \\         ^-_
            -           //  |\\^^/|  \\           -
          _/           //   (0::0)   \\            \\_
         /            ((     \\//     ))             \\
       -               \\    (oo)    //               -
      -                 \\  / \\/ \\  //                 -
     -                   \\/      \\/                   -
   / /|           /\\      (        )      /\\           |\\ \\
   |/ | /\\_/\\_/\\_/  \\_/\\  (   /\\   )  /\\_/  \\_/\\_/\\_/ | \\|
   `  |/  V  V  `    V  \\_(| |  | |)_/  V    '  V  V  \\|  '
      `   `  `       `   / | |  | | \\   '       '  '   '
                       <(  | |  | |  )>
                      <__\\_| |  | |_\\__>
                      ^^^^ ^^^  ^^^ ^^^^^
                        $(CYAN)LIBFT_TESTER$(RESET)
	$(GREEN)(dajesus- "https://github.com/danieljs-dev")$(RESET)
endef
export HEADER

NAME    = libft.a
CC      = cc
CFLAGS  = -g3

LIBFT_DIR ?= ../
TEST_DIR = .

TESTS   = $(wildcard $(TEST_DIR)/test_*.c)

SRCS    = $(shell find $(LIBFT_DIR) -name '*.c')
OBJS    = $(SRCS:$(LIBFT_DIR)%.c=$(LIBFT_DIR)%.o)

INCLUDES = -I$(LIBFT_DIR)

all: print_banner $(LIBFT_DIR)$(NAME)

$(LIBFT_DIR)$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "\r\033[K$(CYAN)LIBFT $(RED)is ready!$(RESET)"

$(LIBFT_DIR)%.o: $(LIBFT_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@clear
	@echo "$(RED)$$HEADER$(RESET)"
	@printf "\r$(CYAN)Compiling $(GREEN)$< $(RESET)"

test: $(LIBFT_DIR)$(NAME)
	@echo "$(GREEN)Running tests...$(RESET)"
	@for test in $(TESTS); do \
		echo "$(CYAN)Testing: $$(basename $$test .c)$(RESET)"; \
		$(CC) $(CFLAGS) $(INCLUDES) -o test_program $$test -L$(LIBFT_DIR) -lft; \
		./test_program; \
		rm -f test_program; \
		echo ""; \
	done

valgrind:
	@echo "$(GREEN)Running Valgrind tests...$(RESET)"
	@quiet=$(QUIET); \
	for test in $(TESTS); do \
		echo "$(CYAN)Testing function with Valgrind: $$(basename $$test .c)$(RESET)"; \
		rm -f test_program; \
		$(CC) $(CFLAGS) $(INCLUDES) -o test_program $$test -L$(LIBFT_DIR) -lft; \
		if [ -f test_program ]; then \
			if [ "$$quiet" = "1" ]; then \
				valgrind -q --leak-check=full --show-leak-kinds=all ./test_program valgrind > /dev/null; \
			else \
				valgrind --leak-check=full --show-leak-kinds=all ./test_program valgrind > /dev/null; \
			fi; \
		else \
			echo "Failed to create test_program"; \
		fi; \
		echo ""; \
	done

clean:
	@echo "$(RED)Removing all .o $(RESET)"
	@rm -f $(LIBFT_DIR)*.o $(TESTS:$(TEST_DIR)/%.c=$(TEST_DIR)/%.o)

fclean: clean
	@echo "$(RED)Removing .a$(RESET)"
	@rm -f $(LIBFT_DIR)$(NAME) test_program
	@sleep 2
	@clear
	@echo "$(RED)$$HEADER$(RESET)"

re: fclean all

print_banner:
	@clear
	@echo "$(RED)$$HEADER$(RESET)"

.PHONY: all clean fclean re test valgrind print_banner
