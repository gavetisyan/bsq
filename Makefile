#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgilwood <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 22:34:59 by bgilwood          #+#    #+#              #
#    Updated: 2018/10/10 21:35:28 by gstiedem         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCDYNAMIC = util/search_dynamic.c main.c util/ft_atoi.c util/ft_bsq.c \
util/ft_fputstr.c util/ft_idigit.c util/ft_isspace.c util/ft_strncpy.c \
util/ft_list_op.c util/ft_check_1_line.c util/ft_strlen.c \
util/ft_check_valid_map.c

INCLUDES = -Iincludes

FLAGS = -Wall -Wextra -Werror

bsq:
	gcc $(FLAGS) $(INCLUDES) $(SRCDYNAMIC) -o bsq

fclean:
	rm -f bsq

re: fclean bsq
