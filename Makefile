# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 17:02:47 by yolee             #+#    #+#              #
#    Updated: 2022/06/17 03:41:52 by yolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(FT_PRINTF_HEADER_DIR) -I $(LIBFT_HEADER_DIR) -I $(SRCS_DIR)
LFLAGS = -L$(FT_PRINTF_LIB_DIR) -lftprintf
FT_PRINTF_HEADER_DIR = ./ft_printf/srcs
FT_PRINTF_LIB_DIR = ./ft_printf
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = libftprintf.a

LIBFT_HEADER_DIR = ./libft

SRCS_DIR = ./
SRCS_FILE = main.c \
	init_func.c \
	make_indexing_lst.c \
	find_input_error.c \
	opt_queue_manage.c \
	optimization.c \
	print_func.c \
	reverse_rotate.c \
	rotate.c \
	push.c \
	sort_hard.c \
	sort_hard_merge.c \
	stack_control.c \
	swap.c \
	radix_sort.c \
 	
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))

OBJS = $(SRCS:.c=.o)

all : $(FT_PRINTF) $(NAME)

$(FT_PRINTF) :
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $? -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $?

clean : 
	$(RM) $(OBJS)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	
re : fclean all
	
.PHONY : all clean fclean re