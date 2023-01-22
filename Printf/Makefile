SRCS = ./utils/ft_printf_char.c\
	   ./utils/ft_printf_do.c\
	   ./utils/ft_printf_format.c\
	   ./utils/ft_printf_init.c\
	   ./utils/ft_printf_is_type.c\
	   ./utils/ft_printf_getprc.c\
	   ./utils/ft_printf_flength.c\
	   ./utils/ft_printf_getprc.c\
	   ./utils/ft_printf_string.c\
	   ./utils/ft_printf_pointer.c\
	   ./utils/ft_printf_putnbr_base.c\
	   ./utils/ft_printf_lengnum.c\
	   ./utils/ft_printf_integer.c\
	   ./utils/ft_printf_unsigned.c\
	   ./utils/ft_printf_hex.c\
	   ./utils/ft_printf_hexa.c\
	   ./utils/ft_printf_percentage.c\
	   ./utils/ft_aux_point_putnbr.c\
	   ./utils/ft_aux_point_lengnbr.c\
	   ./utils/ft_printf_integer_utils.c\
	   ft_printf.c\

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

all : makelibft bonus

.c.o:
	$(CC) $(CFLAGS) -c  $< -o $(<:.c=.o) -I ./libft

makelibft :
			make -C ./libft

bonus : makelibft $(OBJS)
	@cp ./libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

clean :
	@cd libft && make clean
	@$(RM) $(OBJS)

fclean : 
	@cd libft && make fclean
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re
