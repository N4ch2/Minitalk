SRCS = server.c\
	   client.c\
	   
BONUS_SRCS = server_bonus.c\
	   		 client_bonus.c\

OBJS = $(SRCS:.c=)

BONUS_OBJS = $(BONUS_SRCS:.c=)

NAME = project

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

INCLUDE = ./Printf/libftprintf.a

all : $(NAME) 

.c : 
	$(CC) $(CFLAGS) $< $(INCLUDE)  -o $(<:.c=) 

$(INCLUDE) :
	make -C ./Printf

$(NAME) : $(INCLUDE) $(OBJS)
	
bonus :  $(INCLUDE) $(BONUS_OBJS)

clean :
	@cd Printf && make clean
	@echo "objects deleted"

fclean : 
	@cd Printf && make fclean
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "programs deleted"

re : fclean all

.PHONY: all clean fclean re