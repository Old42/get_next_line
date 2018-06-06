#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strnjoin(char *stock, const char *buffer, int indice_nl);
char		*ft_strunjoin(char **line, char *stock, unsigned int indice_nl);
char	*ft_strcpyfromn(const char *buffer, int indice_nl, int read_len);



#endif