# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evlasov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/29 19:17:34 by evlasov           #+#    #+#              #
#    Updated: 2018/09/29 19:17:38 by evlasov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = includes/ft_printf.h
OPTION = -c -I $(HEADER)
FLAG = -Wall -Wextra -Werror
#SRCDIR = srcs
SRC = srcs/*.c
OBJ = ft_printf.o args_handling.o apply_flags.o apply_id.o apply_s.o ft_itoa_ll.o apply_c.o \
	apply_o.o apply_u.o apply_x.o apply_p.o ft_itoa_cc.o ft_uitoa_cc.o size_mod.o \
	ft_uitoa_ll.o libft/*.o
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAG) $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make clean -C libft
	rm -rf $(OBJ)	

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re
