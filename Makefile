# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: truthe <truthe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 12:03:34 by cgretche          #+#    #+#              #
#    Updated: 2022/06/08 16:52:11 by truthe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

			
HEADER		=	include/minishell.h
OBJS	=		$(SRC:%.c=%.o)
CC		=		gcc
CFLAGS	=		-Wall -Wextra -Werror -g
READLINE	=	-L /Users/$(USER)/.brew/opt/readline/lib -lreadline
LIBS		=	-L libft -lft
SRC_DIR		=	src/
MOD_DIR		=	libft_mod/

SRC			=	$(addprefix $(SRC_DIR), minishell.c ft_preparsing.c ft_spaces.c utils.c ft_parse_dollar.c \
				ft_heredoc.c check_pipe_and_redirect.c parse_execve.c ft_signals.c ft_shlvl.c ft_check_syntax.c pipe_execute_comand.c comand_cd.c dollar_question.c \
				ft_env.c ft_print_env.c ft_exit.c ft_unset.c get_old_pwd.c get_really_pwd.c ft_export_pars.c ft_export_sort.c ft_export.c norm_fd.c ft_preparsing_main.c) \
				$(addprefix $(MOD_DIR), split_mod.c ft_list_utils.c ft_strcmp_mod.c ft_split_mod_2.c)\

OBJS	=		$(SRC:%.c=%.o)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@make -C libft
			@$(CC) $(LIBS) $(READLINE) $(CFLAGS) $(OBJS) -o $(NAME)

%.o 	:	%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean		:
				@make -C libft clean
				$(RM) $(OBJS)
fclean		:	clean
				@make -C libft fclean
				$(RM) $(NAME)

re		:	fclean all
