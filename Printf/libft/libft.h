/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:54:05 by joramire          #+#    #+#             */
/*   Updated: 2022/10/03 16:45:03 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*Includes*/
# include	<unistd.h>
# include	<stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*Libc*/

/*Convert ASCII string to integer*/
int			ft_atoi(const char *str);
/*Writes n zeroed bytes to the string s*/
void		ft_bzero(void *s, size_t n);
/*Save space for count objects of size memory and returns the pointer to it*/
void		*ft_calloc(size_t count, size_t size);
/*Test if all characters are alphanumeric*/
int			ft_isalnum(int c);
/*Test if all characters are alphabetic*/
int			ft_isalpha(int c);
/*Test if all characters belong to the Ascii table*/
int			ft_isascii(int c);
/*Test if all characters are digits*/
int			ft_isdigit(int c);
/*Test if all characters are printables, it include ' '*/
int			ft_isprint(int c);
/*Locates the first occurrence of c in string s and returns a pointer to it*/
void		*ft_memchr(const void *s, int c, size_t n);
/*Compares byte string s1 against byte string s2*/
int			ft_memcmp(const void *s1, const void *s2, size_t n);
/*Copies n bytes from memory area src to memory area dst (no work overlaping)*/
void		*ft_memcpy(void *dst, const void *src, size_t n);
/*Copies len bytes from string src to string dst (work overlaping)*/
void		*ft_memmove(void *dst, const void *src, size_t len);
/*Writes len bytes of value c to the string b*/
void		*ft_memset(void *b, int c, size_t len);
/*Locates the first occurrence of c in string s and returns a pointer to it*/
char		*ft_strchr(const char *s, int c);
/*Locates the last occurrence of c in string s and returns a pointer to it*/
char		*ft_strrchr(const char *s, int c);
/*Save memory for copy of s1 does the copy and returns a pointer to it*/
char		*ft_strdup(const char *s1);
/*Appends string src to the end of dst*/
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
/*Copies up to dstsize - 1 characters from the string src to dst*/
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
/*Computes the length of the string s*/
size_t		ft_strlen(const char *s);
/*Compare not more than n characters of the strings s1 and s2*/
int			ft_strncmp(const char *s1, const char *s2, size_t n);
/*Locates the first occurrence of needle in haystack at most len characters*/
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
/*Converts an upper-case letter to the corresponding lower-case letter*/
int			ft_tolower(int c);
/*Converts a lower-case letter to the corresponding upper-case letter*/
int			ft_toupper(int c);
/*Outputs the string s to the given file descriptor followed by a newline*/
void		ft_putendl_fd(char *s, int fd);

/*Additional*/

/*Convert integer to ASCII string*/
char		*ft_itoa(int n);
/*Returns a list of words in s separated by c*/
char		**ft_split(char const *s, char c);
/*Concatenate s1 and s2*/
char		*ft_strjoin(char const *s1, char const *s2);
/*Returns copy of ’s1’ with ’set’ removed from the beginning and end*/
char		*ft_strtrim(char const *s1, char const *set);
/*Returns a substring from s that begins at start and is of maximum size len*/
char		*ft_substr(char const *s, unsigned int start, size_t len);
/*Applies the function f to each character of the string s*/
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*Applies the function f on each character of the string passed as argument*/
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
/*Outputs the character c to the given file descriptor*/
void		ft_putchar_fd(char c, int fd);
/*Outputs the string s to the given file descriptor*/
void		ft_putstr_fd(char *s, int fd);
/*Outputs the integer n to the given file descriptor*/
void		ft_putnbr_fd(int n, int fd);

/*Bonus*/

/*Returns a new node with content initialized to a input and next NULL*/
t_list		*ft_lstnew(void *content);
/*Adds the node new at the beginning of the list*/
void		ft_lstadd_front(t_list **lst, t_list *new);
/*Counts the number of nodes in a list*/
int			ft_lstsize(t_list *lst);
/*Returns the last node of the list*/
t_list		*ft_lstlast(t_list *lst);
/*Adds the node new at the end of the list*/
void		ft_lstadd_back(t_list **lst, t_list *new);
/*Takes a node and frees content using del and free the node*/
void		ft_lstdelone(t_list *lst, void (*del)(void *));
/*Deletes and frees the given node and every successor of that node using del*/
void		ft_lstclear(t_list **lst, void (*del)(void *));
/*Iterates the lst and applies f on the content of each node*/
void		ft_lstiter(t_list *lst, void (*f)(void *));
/*Iterates the list lst and applies the function f on the content of each node*/
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
