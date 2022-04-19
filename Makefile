LIBFT	=	libft/ft_strncmp.c \
			libft/ft_split.c \
			libft/ft_strjoin.c \
			libft/ft_strlen.c \

UTILITY =	utils.c

SRCS =	$(LIBFT) \
		$(UTILITY) \
		main.c

NAME	=	pipex
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra 
INCLUDE =	-I include
BONUS =

OBJS	=		$(SRCS:.c=.o)
OBJS_BONUS =	$(BONUS:.c=.o)
EXEC = pipex

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