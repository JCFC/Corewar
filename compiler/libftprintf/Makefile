# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchen <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/20 17:54:36 by jchen             #+#    #+#              #
#    Updated: 2016/06/20 17:54:53 by jchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

INCLUDE			= includes/
CFLAGS			= -O3 -Wall -Werror -Wextra
CC				= $(SILENCE)gcc

SRCS			= \
			ft_printf.c\
			ft_printf_bracket.c\
			ft_printf_detect.c\
			ft_printf_flag.c\
			ft_printf_format_cdbpercent.c\
			ft_printf_format_oxup.c\
			ft_printf_format_parse.c\
			ft_printf_format_s.c\
			ft_printf_format_s_2.c\
			ft_printf_stringarg.c\
			ft_printf_wchar.c\
			ft_printf_wchar_2.c\

SRCDIR			= ./srcs/
SRC				= $(addprefix $(SRCDIR), $(SRCS))
OBJS			= $(SRC:.c=.o)

V				= 0
SILENCE_1		:=
SILENCE_0		:=@
SILENCE			= $(SILENCE_$(V))

LIB				= $(SILENCE)ar rc
RM				= $(SILENCE)rm -rf

SKIP_1 			:=
SKIP_0 			:= \033[A
SKIP 			= $(SKIP_$(V))

COLOR1			= \033[0;36m
COLOR2			= \033[1;32m
COLOR3			= \033[1;31m
EOC				= \033[0m

all: $(NAME)

$(NAME):$(OBJS)
	$(LIB) $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
