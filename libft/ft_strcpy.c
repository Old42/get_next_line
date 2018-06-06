#include <stdlib.h>
#include "header.h"

char	*ft_strcpy(char *dest, char *src)
{
	int				i;
	size_t			src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (!(dest = malloc(src_len + 1)))
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}