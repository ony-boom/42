/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 05:57:07 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/26 07:19:22 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "stdlib.h"

int				ft_isinrange(int n, int min, int max);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_strlen(const char *str);
void			*ft_memset(void *s, int c, unsigned int n);
void			ft_bzero(void *s, int n);
void			*ft_memcpy(void *dest, const void *src, int n);
void			*ft_memmove(void *dest, const void *src, int n);
int				ft_strlcpy(char *dst, const char *src, int size);
char			*ft_strncat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, int n);
void			*ft_memchr(const void *s, int c, int n);
int				ft_memcmp(const void *s1, const void *s2, int n);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strnstr(const char *big, const char *little, int len);
int				ft_isspace(int c);
char			*trim_start(char *str);
int				ft_isnum(char c, int *c_as_int);
int				ft_atoi(const char *base_str);
void			*ft_calloc(int nitems, int size);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, int len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
long			ft_abs(long n);
#endif // LIBFT_H
