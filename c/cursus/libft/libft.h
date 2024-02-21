/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 05:57:07 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/21 06:24:03 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

int ft_isinrange(int n, int min, int max);
int ft_isupper(int c);
int ft_islower(int c);
int ft_isdigit(int c);
int ft_isalpha(int c);
int ft_isalnum(int c);
int ft_isprint(int c);
int ft_strlen(const char *str);
void *ft_memset(void *s, int c, int n);
void ft_bzero(void *s, int n);
void *ft_memcpy(void *dest, const void *src, int n);
void *ft_memmove(void *dest, const void *src, int n); 
int strlcpy(char *dst, const char *src, int size);
char	*ft_strncat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int ft_toupper(int c);
int ft_tolower(int c);
char *ft_strchr(const char *s, int c);

#endif // LIBFT_H
