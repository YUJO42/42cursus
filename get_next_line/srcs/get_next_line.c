/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 14:24:20 by yujo              #+#    #+#             */
/*   Updated: 2020/04/19 18:18:56 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 1. fd, line, BUFFER_SIZE가 valid check.
** 2. valid (1) -> save read(fd, buff, buffer_size) return value another var
** 3. 
**
*/

static int	handle_line(char **line, char **note, char *nl_here)
{
	char	*tmp;

	if (nl_here != NULL)
	{
		*line = ft_strndup(*note, nl_here - *note);
		tmp = ft_strndup(nl_here + 1, ft_strlen(nl_here + 1));
		free(*note);
		*note = tmp;
		return (NL);
	}
	if (*note != NULL)
	{
		*line = *note;
		*note = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (_EOF);
}

int		get_next_line(int fd, char **line)
{
	static char	*note[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			byte;
	char		*tmp;
	char		*nl_here;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (ERROR);
	while ((nl_here = ft_strchr(note[fd], '\n')) == 0
		&& (byte = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[byte] = 0;
		tmp = note[fd] == NULL ? ft_strndup(buff, byte) :
			ft_strjoin(note[fd], buff);
		if (note[fd] != 0)
			free(note[fd]);
		note[fd] = tmp;
	}
	if (byte < 0)
		return (ERROR);
	return (handle_line(line, &note[fd], nl_here));
}
