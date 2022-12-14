gnl = 	get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c

NAME = pipex.a

compile:
	make -C libft all
	make -C printf all
	gcc -Wall -Werror -Wextra -I get_next_line/get_next_line_bonus.h -c ${gnl}
	cp libft/libft.a ${NAME}
	cp printf/libftprintf.a ${NAME}
	ar rcs ${NAME} ${OBJSPIPEX} get_next_line_bonus.o get_next_line_utils_bonus.o

all:	$(NAME)

clean :
	make -C libft clean
	make -C printf clean
	rm -f get_next_line.o get_next_line_utils_bonus.o
	rm -f $(OBJS) $(OBJBONUS)

fclean: clean
	make -C libft fclean
	make -C printf fclean
	rm -f get_next_line/a.out
	rm -f pipex.a

re: fclean all

.PHONY : all clean fclean bonus