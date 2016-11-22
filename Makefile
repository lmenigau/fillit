#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/18 02:18:30 by lmenigau          #+#    #+#             *#
#*   Updated: 2016/11/22 00:44:29 by lmenigau         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME	= fillit
SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)
CFLAGS	= -Wall -Wextra -Werror -Ilibft/
CFLAGS	+= -g
LFLAGS	= -lft
LDFLAGS	= -Llibft/
LIBDIR	= libft/
LIB		:= $(LIBDIR)/libft.a

.PHONY	:	all clean fclean re lib

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(LIB)
			$(CC) $(CFLAGS) $(LFLAGS) $(LDFLAGS) -o $@ $(OBJ)

$(LIB)	:	$(LIBDIR)
			$(MAKE) -C $(LIBDIR)

clean	:	$(OBJ)
			$(RM) $(OBJ)
