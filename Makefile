# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 17:02:47 by yolee             #+#    #+#              #
#    Updated: 2022/06/10 18:01:14 by yolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(FT_PRINTF_HEADER_DIR) -I $(LIBFT_HEADER_DIR) -I $(SRCS_DIR)
LFLAGS = -L$(FT_PRINTF_LIB_DIR) -lftprintf
FT_PRINTF_HEADER_DIR = ./ft_printf/srcs
FT_PRINTF_LIB_DIR = ./ft_printf
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = libftprintf.a

LIBFT_HEADER_DIR = ./libft

SRCS_DIR = ./
SRCS_FILE = push_swap.c \
	init_func.c \
	input_validation.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	stack_control.c \
	swap.c \
	sort_func.c \
	sort_hard.c \
	optimization.c \
	print_func.c \
 	
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))

SRCS_DIR_B = ./bonus
SRCS_FILE_B = ft_printf_bonus.c \
	flag_control_bonus.c \
	manage_format_str_bonus.c \
	parse_char_bonus.c \
	parse_decimal_bonus.c \
	parse_etc_bonus.c \
	parse_lower_hexadecimal_bonus.c \
	parse_ptr_bonus.c \
	parse_str_bonus.c \
	parse_unsigned_decimal_bonus.c \
	parse_upper_hexadecimal_bonus.c \

SRCS_B = $(addprefix $(SRCS_DIR_B)/, $(SRCS_FILE_B))
	
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef BONUS_FLAG
	OBJS = $(OBJS_B)
endif

all : $(FT_PRINTF) $(NAME)

$(FT_PRINTF) :
	$(MAKE) -C $(FT_PRINTF_DIR)

bonus :
	$(MAKE) BONUS_FLAG=1

%.o : %.c
	$(CC) $(CFLAGS) -c $? -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $?

clean : 
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	
re : fclean all
	
.PHONY : bonus all clean fclean re