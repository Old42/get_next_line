#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2

typedef struct s_string t_string;
struct		s_string
{
	char		*str;
	int			fd;
	t_string	*next;
};

int get_next_line(const int fd, char **line);

#endif