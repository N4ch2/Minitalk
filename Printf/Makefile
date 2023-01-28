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

OBJS_LIBFT = 	libft/ft_isalpha.o\
				libft/ft_isdigit.o\
				libft/ft_isalnum.o\
				libft/ft_isascii.o\
				libft/ft_isprint.o\
				libft/ft_strlen.o\
				libft/ft_strchr.o\
				libft/ft_strrchr.o\
				libft/ft_strncmp.o\
				libft/ft_strlcpy.o\
				libft/ft_strlcat.o\
				libft/ft_strnstr.o\
				libft/ft_memset.o\
				libft/ft_memcmp.o\
				libft/ft_bzero.o\
				libft/ft_memcpy.o\
				libft/ft_memchr.o\
				libft/ft_memmove.o\
				libft/ft_toupper.o\
				libft/ft_tolower.o\
				libft/ft_atoi.o\
				libft/ft_calloc.o\
				libft/ft_strdup.o\
				libft/ft_substr.o\
				libft/ft_strjoin.o\
				libft/ft_strtrim.o\
				libft/ft_split.o\
				libft/ft_itoa.o\
				libft/ft_strmapi.o\
				libft/ft_striteri.o\
				libft/ft_putchar_fd.o\
				libft/ft_putstr_fd.o\
				libft/ft_putendl_fd.o\
				libft/ft_putnbr_fd.o\

NAME = libftprintf.a

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c  $< -o $(<:.c=.o) -I ./libft

$(NAME) : $(OBJS)
	@make -C ./libft
	@ar rcs $(NAME) $(OBJS_LIBFT) $(OBJS)
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
