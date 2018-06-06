#include <malloc.h>

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
	{
		str[k] = s2[i];
		k++;
		i++;
	}
	str[k] = '\0';
	free(s1);
	return (str);
}