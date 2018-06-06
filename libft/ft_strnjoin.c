#include <stdlib.h>

char	*ft_strnjoin(char *stock, const char *buffer, int indice_nl)
{
	char			*str;
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (stock)
		while (stock[i] != '\0')
			i++;
	if (!(str = malloc(i + indice_nl + 1)))
		return (NULL);
	while (k < i)
	{
		str[k] = stock[k];
		k++;
	}
	i = 0;
	while (i < indice_nl)
		str[k++] = buffer[i++];
	str[k] = '\0';
	free(stock);
	stock = NULL;
	return (str);
}
