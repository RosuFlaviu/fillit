# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frosu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/09 15:46:07 by frosu             #+#    #+#              #
#    Updated: 2017/03/09 15:46:08 by frosu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a

NAME_OUT = fillit

SRC = checking_matrix.c \
		ft_is_file_valid.c \
		swap_rows.c \
		swap_collumns.c \
		basic_check.c \
		verify_matrix.c \
		copy_matrix.c \
		restrain.c \
		solver.c\
		main.c

OBJ = $(SRC:.c=.o)

INCL = -I fillit.h -I libft/libft.h

all: $(NAME)

$(NAME):
		make -C ./libft/
	    gcc -Wall -Werror -Wextra $(INCL) -c $(SRC)
		gcc $(OBJ) -L libft/ -lft -o $(NAME_OUT)
	    ar rc $(NAME) $(OBJ)
	    ranlib $(NAME)
clean:
	make clean -C ./libft/
	rm -rf $(OBJ)
fclean: clean
	make fclean -C ./libft/
	rm -rf $(NAME) $(NAME_OUT)
re:	fclean all
