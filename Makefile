LIBFT 	=	libft/ft_strlen.c \
			libft/ft_atoi.c \
			libft/ft_split.c \
			libft/ft_isdigit.c \
			libft/ft_putendl_fd.c \

UTILITY =	utility/ft_check_doubles.c \
			utility/print_list.c \
			utility/ft_error.c \
			utility/ft_free.c \
			utility/ft_tabtab_to_tab.c \
			utility/ft_count_double_tab.c \
			utility/ft_n_ops.c \
			utility/ft_greater_than.c \
			utility/ft_min.c \

LIST_OPS =	list_ops/ft_lstnew.c \
			list_ops/ft_lstadd_back.c\
			list_ops/ft_tab_to_list.c\
			list_ops/ft_lstadd_front.c\
			list_ops/ft_lstlast.c\
			list_ops/ft_lstclear.c \
			list_ops/ft_lstsize.c \
			list_ops/ft_lstmin.c \
			list_ops/ft_lstmax.c \

OPERATIONS =operations/ft_sa.c \
			operations/ft_sb.c \
			operations/ft_ra.c \
			operations/ft_rb.c \
			operations/ft_rra.c \
			operations/ft_rrb.c \
			operations/ft_pb.c \
			operations/ft_pa.c \
			operations/ft_ss.c \
			operations/ft_rr.c \
			operations/ft_rrr.c \

ALGO =	algorithms/ft_redirect.c \
		algorithms/ft_three_elem_sort.c \
		algorithms/ft_two_elem_sort.c \
		algorithms/ft_five_elem_sort.c \
		algorithms/ft_hundred_elem_sort.c \
		algorithms/ft_output_check.c \
		algorithms/radix_sort.c \

SRCS =	$(ALGO) \
		$(LIBFT) \
		$(UTILITY) \
		$(LIST_OPS) \
		$(OPERATIONS)\
		main.c

NAME	=	push_swap
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra 
INCLUDE =	-I include
BONUS =

OBJS	=		$(SRCS:.c=.o)
OBJS_BONUS =	$(BONUS:.c=.o)
EXEC = push_swap

RM		=		@rm -f

.c.o:
			@$(CC) $(FLAGS) -c -I include $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(EXEC)

all:		$(NAME)

bonus:		$(OBJS_BONUS)
			$(CC) $(FLAGS) $(OBJS_BONUS)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(EXEC)

re:			fclean all