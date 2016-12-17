PUSH_SWAP = push_swap

CHECKER = checker

COMMON = check_arguments.c is_numeric.c main.c init_pile.c \
	print_pile.c is_int.c destruct_pile.c push.c swap.c extremum.c \
	int_cpy.c rotate.c reverse_rotate.c check_dubs.c options.c get_next_line.c\
	free_table.c print_int.c comparison.c

PSH_SWP = solve.c error.c is_push_swap.c quicksort.c calculate_distance.c \
	  prepare_for_pivot.c pivot.c roll_pile.c sort_both.c \
	  sort_simple.c

CHCKR = checker.c ko.c read_input.c execute.c isnt_push_swap.c check_sorted.c

INCLUDE = -I includes/

FLAG = -Wall -Wextra -Werror -g

CCOMMON = $(addprefix common/, $(COMMON))
CCHECKER = $(addprefix src_checker/, $(CHCKR))
CPUSH = $(addprefix src_push/, $(PSH_SWP))

PUSH_OBJ = $(PSH_SWP:.c=.o)
CHECKER_OBJ = $(CHCKR:.c=.o)
COMMON_OBJ = $(COMMON:.c=.o)

LIBRARIES = -L libft/ -L ft_printf/ -lft -lftprintf

all: $(PUSH_SWP) $(CHECKER)

$(PUSH_SWAP) $(CHECKER):
	@gcc -c $(FLAG) $(INCLUDE) $(CCOMMON) $(CPUSH) $(CCHECKER)
	@gcc -o $(CHECKER) $(LIBRARIES) $(COMMON_OBJ) $(CHECKER_OBJ)
	@gcc -o $(PUSH_SWAP) $(LIBRARIES) $(COMMON_OBJ) $(PUSH_OBJ)
	@mkdir obj && mv $(COMMON_OBJ) $(PUSH_OBJ) $(CHECKER_OBJ) obj
	@echo "\x1b[32;01m$(PUSH_SWAP) and $(CHECKER) ready\x1b[0;m"

clean:
	@/bin/rm -rf obj
	@/bin/rm -rf $(COMMON_OBJ) $(PUSH_OBJ) $(CHECKER_OBJ)
	@echo "\x1b[32;01mclean\x1b[0;m"

fclean: clean
	@/bin/rm -f $(PUSH_SWAP) $(CHECKER)
	@echo "\x1b[32;01mfclean\x1b[0;m"

re: fclean all
