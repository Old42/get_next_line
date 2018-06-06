NAME = libft.a

FILES += ft_strlen.c
FILES += ft_strcpy.c
FILES += ft_strjoin.c
FILES += ft_strnjoin.c
FILES += ft_strunjoin.c
FILES += ft_strcpyfromn.c

OBJS = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FILES) -I. ${FLAGS}
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
