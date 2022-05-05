# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 17:33:31 by wdebotte          #+#    #+#              #
#    Updated: 2022/05/05 23:00:55 by wdebotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# => TEXT
################################################################################

END		= \033[0m
BOLD	= \033[1m

RED		= \033[91m
GREEN	= \033[92m
YELLOW	= \033[93m

################################################################################
# => VARIABLES
################################################################################

NAME		= libftprintf.a

PATHSRCS	= ./srcs/
PATHNULL	= /dev/null

SRCS 		= ${PATHSRCS}printf.c \
			${PATHSRCS}putnbrs.c \
			${PATHSRCS}utils.c

OBJS		= ${SRCS:.c=.o}

HEADERS		= ./printf.h

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I.

RM			= rm -rf

NORM		= norminette
FLAGC		= -R CheckForbiddenSourceHeader
FLAGH		= -R CheckDefine

################################################################################
# => RULES
################################################################################

.c.o:
				@echo "${BOLD}${YELLOW}Compiling:${END}\t$<"
				@${CC} ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o} >${PATHNULL}

all:		${NAME}

${NAME}:	${OBJS}
				@echo "${BOLD}${GREEN}Building:${END}\t${NAME}"
				@ar -rc ${NAME} ${OBJS} >${PATHNULL}

clean:
				@echo "${BOLD}${RED}Removing:${END}\tAll .o files"
				@${RM} ${OBJS} >${PATHNULL}

fclean:		clean
				@echo "${BOLD}${RED}Removing:${END}\t${NAME}"
				@${RM} ${NAME} >${PATHNULL}

re:			fclean all

norminette:
				@echo "${BOLD}${YELLOW}Norminette:${END}\tAll .c files"
				${NORM} ${FLAGC} ${SRCS}
				@echo "${BOLD}${GREEN}Norminette:${END}\tOK !"
				@echo "${BOLD}${YELLOW}Norminette:${END}\tAll .h files"
				${NORM} ${FLAGH} ${HEADERS}
				@echo "${BOLD}${GREEN}Norminette:${END}\tOK !"

.PHONY:		all clean fclean re norminette

################################################################################
