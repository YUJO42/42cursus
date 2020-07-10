/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:31:03 by yujo              #+#    #+#             */
/*   Updated: 2020/07/11 06:21:12 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strcpy_nl(char **in, int i)
{
	int		j;
	char	*res;
	char	*tmp;

	while ((*in)[i] != '\0' && (*in)[0] != '\n')
		if ((*in)[++i] == '\n')
			break ;
	res = malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	j = i;
	if (*(*in + i + 1) != '\0' && *(*in + i) != '\0')
		tmp = ft_strdup(*in + i + 1);
	else if (!*(*in + i))
		tmp = ft_strdup("");
	else
		tmp = NULL;
	while (--j >= 0)
	{
		res[j] = (*in)[j];
		(*in)[j] = 0;
	}
	free(*in);
	*in = tmp;
	return (res);
}

static int		has_newline(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

static int		process(int fd, char **s, int y, char **line)
{
	if (y > 0)
	{
		*line = ft_strcpy_nl(&s[fd], 0);
		return (1);
	}
	else if (s[fd])
	{
		if (has_newline(s[fd]) > 0)
		{
			*line = ft_strcpy_nl(&s[fd], 0);
			return (1);
		}
		*line = ft_strcpy_nl(&s[fd], 0);
		free(s[fd]);
		s[fd] = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			n;
	int			y;
	static char	*s[OPEN_MAX];
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	y = 0;
	if (s[fd] && BUFFER_SIZE >= 8 && has_newline(s[fd]) > 0)
		return (process(fd, s, 1, line));
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = '\0';
		y = has_newline(buf);
		tmp = s[fd];
		s[fd] = ft_strjoin(tmp, buf);
		free(tmp);
		if (y > 0)
			break ;
	}
	if (n < 0)
		return (-1);
	return (process(fd, s, y, line));
}

