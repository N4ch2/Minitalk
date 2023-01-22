/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:16:35 by joramire          #+#    #+#             */
/*   Updated: 2023/01/01 23:28:42 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUTILS_H
# define LIBUTILS_H

/*Includes*/
# include	<stdbool.h>
# include	<unistd.h>
# include	<stdarg.h> 
# include	"../libft/libft.h"

typedef struct s_pinfo
{
	va_list		arg;
	int			width;
	int			prc;
	int			dash;
	int			zero;
	int			point;
	int			alng;
	int			sign;
	int			space;
	int			hastag;
}				t_pinfo;

/*Initialise the structure of the print info*/
void		ft_printf_init(t_pinfo *info);
/*Check if the character is a type character*/
bool		ft_printf_is_type(char c);
/*(Copy)Set the format information in the struct*/
void		ft_printf_format(char *format, t_pinfo *info);
/*Redirect formatting info and return the length of the format*/
int			ft_printf_do(const char *format, t_pinfo *info);
/*Print the characters with the correct format*/
void		ft_printf_char(t_pinfo *info);
/*Print strings with the correct format*/
void		ft_printf_string(t_pinfo *info);
/*Print pointers with the correct format*/
void		ft_printf_pointer(t_pinfo *info);
/*Print integers with the correct format*/
void		ft_printf_integer(t_pinfo *info);
/*Return the length of the format*/
int			ft_printf_flength(const char *str);
/*Obtain the precision for certain flags*/
int			ft_printf_getprc(const char *str);
/*Write the number in another base*/
int			ft_printf_putnbr_base(long long int nbr, char *base);
/*Compute the length in a certain base*/
int			ft_printf_lengnum(long long int nbr, char *base, int swch);
/*Print unsigned ints with the correct format*/
void		ft_printf_unsigned(t_pinfo *info);
/*Print hexadecimal numbers with the correct format lowercase*/
void		ft_printf_hex(t_pinfo *info);
/*Print hexadecimal numbers with the correct format uppercase*/
void		ft_printf_hexa(t_pinfo *info);
/*Print a percentage*/
void		ft_printf_percentage(t_pinfo *info);
/*Auxiliar functions for the pointers*/
int			ft_aux_point_putnbr(unsigned long long nbr, char *base);
int			ft_aux_point_lengnbr(unsigned long long nbr, char *base, int swch);
/*Auxiliar functions for the integers*/
int			ft_integer_max(int n, int m);
void		ft_printf_integer_space(t_pinfo *info, int max);
void		ft_printf_integer_zeros(t_pinfo *info, int length_num,
				int n, int aux);

#endif
