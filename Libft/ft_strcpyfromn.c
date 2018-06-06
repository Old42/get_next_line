#include <stdlib.h>

char	*ft_strcpyfromn(const char *buffer, int indice_nl, int read_len)
{
	int		i;
	int		len;
	char	*stock;

	len = read_len - indice_nl;
	if (!(stock = malloc(len)))
		return (NULL);

	i = 0;
	indice_nl++;
	while(i < len - 1)
	{
		stock[i] = buffer[indice_nl];
		i++;
		indice_nl++;
	}
	stock[i] = '\0';
	return (stock);
}