#include "strings_functions.h"
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int				i;
	size_t			src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dest != NULL)
		free(dest);
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

char	*ft_strjoin(char *s1, const char *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	if (s1)
		while (s1[i] != '\0')
			i++;
	while (s2[j] != '\0')
		j++;
	if (!(str = malloc(i + j + 1)))
		return (NULL);
	while (k < i)
	{
		str[k] = s1[k];
		k++;
	}
	i = 0;
	while (i < j)
		str[k++] = s2[i++];
	str[k] = '\0';
	free(s1);
	return (str);
}

/*
 * Creer une chaine de caractere a partir de celle deja stockee en entier (ne contient pas
 * de '\n') et copie n caractere d'une autre chaine contenant un '\n' (jusqu'au '\n')
 */

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
	free(stock);//free la chaine de caractere precedente sinon elle est perdue lors du re-referencage
	stock = NULL;
	return (str);
}

/*
 * Prends la derniere chaine de caractere stockee et la divise en 2 partie :
 * Ce qu'il y a avant le '\n' et ce qu'il y a apres.
 */

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

/*
 * Ft_strcpyfromn stocke les caracteres depassant apres le '\n' dans le buffer
 */
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