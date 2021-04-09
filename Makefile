CC = gcc -lncurses
TARGET = minishell

OBJS =	./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		./srcs/hyeolee_minishell.c \
		./srcs/init_path.c


all : $(TARGET)

$(TARGET) : $(OBJS)
	make -C libft
	cp ./libft/libft.a .
	$(CC) $(OBJS) -o $@ libft.a

clean :
	rm -rf $(TARGET)
	rm -rf libft.a
	rm -rf ./libft/libft.a

fclean : clean
	rm -rf $(TARGET)

re : clean all
