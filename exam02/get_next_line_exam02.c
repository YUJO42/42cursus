#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*buf;

	if (!(buf = malloc(sizeof(char) * (ft_strlen(s1)+ ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (*s1)
		buf[i++] = *s1++;
	while (*s2)
		buf[i++] = *s2++;
		buf[i] = '\0';
		return (buf);
}

int		get_next_line(char **line)
{
	int		size;
	char	buf[2];
	char	*store;
	char	*temp;

	size = 1;
	store = ft_strjoin("", "");
	buf[size] = '\0';
	while (size && buf[0] != '\n')
	{
		size = read(3, buf, 1);
		if (buf[0] != '\n')
		{
			temp = ft_strjoin(store, buf);
			free (store);
			store = temp;
		}
	}
	*line = store;
	return (size);
}
