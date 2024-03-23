#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned char	*src;

	src = (unsigned char *)s;
	while (n)
	{
		*src = (unsigned char)c;
		src++;
		n--;
	}
	return (s);
}

void	*ft_calloc(int nitems, int size)
{
	unsigned char	*mem;

	mem = malloc(nitems * size);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, nitems * size);
	return (mem);
}

int	ft_strlcpy(char *dst, const char *src, int size)
{
	unsigned int	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (i < (unsigned int)(size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

char	*ft_strdup(const char *src)
{
	int		len;
	char	*new;

	len = ft_strlen(src);
	new = malloc((len + 1) * sizeof(char));
	if (new == 0)
		return (0);
	ft_strlcpy(new, src, len + 1);
	return (new);
}
