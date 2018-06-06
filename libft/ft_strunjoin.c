#include <stdlib.h>

char		*ft_strunjoin(char **line, char *stock, unsigned int indice_nl)
{
	unsigned int	i;
	char			*new_stock;
	i = 0;
	if (*line != NULL)
		free (*line);
	if (!(*line = malloc(indice_nl + 1)))
	{
		*line = NULL;
		return (NULL);
	}
	while (i < indice_nl)
	{
		(*line)[i] = stock[i];
		i++;
	}
	(*line)[i++] = '\0'; //on depasse le \n
	while (stock[i] != '\0')
		i++;
	if (!(new_stock = malloc(i - indice_nl)))
		return (NULL);
	i = 0;
	indice_nl++;
	while (stock[indice_nl] != '\0')
		new_stock[i++] = stock[indice_nl++];
	new_stock[i] = '\0';
	free(stock);
	return (new_stock);
}