# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 14:19:38 by rchbouki          #+#    #+#              #
#    Updated: 2023/06/21 16:52:11 by rchbouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -f
HEADER = -I ./includes
NAME = fractol
OBJS = ${SRCS_MAIN:.c=.o}
SRCS = mandelbrot.c \
	julia.c \
	parsing.c \
	mlx_draw.c \
	fractol_utils.c \
	mlx_hook_utils.c \
	ft_printf_utils.c \
	ft_printf.c \
	ft_write.c \

GREEN = "\033[1;32m"
RED = "\033[1;31m"
WHITE = "\033[1;37m"
EOC = "\033[0;0m"

SRCS_MAIN = main.c ${SRCS}

.c.o :
	@${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	@echo $(GREEN)"     Compiling Riri's Fractol..."$(EOC)
	@${CC} ${CFLAGS} -lm -lmlx -framework AppKit -framework OpenGL -g -o ${NAME} ${OBJS}

norminette:
	@norminette | grep "Error!" > /dev/null && echo $(WHITE)"     Norminette: "$(RED)"[KO]"$(EOC) || echo $(WHITE)"     Norminette: "$(GREEN)"[OK]"$(EOC)	

all : ${NAME} norminette

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
