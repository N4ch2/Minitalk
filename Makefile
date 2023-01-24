SRCS = server.c\
	   client.c\

NAME = libftprintf.a

SERVER = server

CLIENT = client

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

INCLUDE = ./Printf/libftprintf.a

all : lib $(NAME)

lib :
	make -C ./Printf

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $< $(INCLUDE) -o $(SERVER)
	$(CC) $(CFLAGS) $(word 2,$^) $(INCLUDE) -o $ $(CLIENT)
	

clean :
	@cd Printf && make clean
	@$(RM) $(SERVER)
	@$(RM) $(CLIENT)

fclean : 
	@cd Printf && make fclean
	@$(RM) $(SERVER)
	@$(RM) $(CLIENT)


re : fclean all

.PHONY: all clean fclean re