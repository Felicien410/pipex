OBJSPIPEX = pipex.c get_env.c

NAME = pipex.a

compile:
	make -C libft all
	make -C printf all
	cp libft/libft.a ${NAME}
	cp printf/libftprintf.a ${NAME}
	ar rcs ${NAME} ${OBJSPIPEX} 

all:	$(NAME)

clean :
	make -C libft clean
	make -C printf clean

	rm -f $(OBJS) $(OBJBONUS)

fclean: clean
	make -C libft fclean
	make -C printf fclean
	rm -f get_next_line/a.out
	rm -f pipex.a

re: fclean all

.PHONY : all clean fclean bonus
