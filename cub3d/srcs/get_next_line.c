/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:46:35 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 15:31:08 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/cub3d.h"

void	save_in_tmp(char *buf, int size, int idx, char **tmp)
{
	if (*tmp)
		free(*tmp);
	if (size - idx)
	{
		*tmp = malloc(sizeof(char) * (size - idx + 1));
		ft_strlcpy_g(*tmp, buf + idx, (size - idx + 1));
	}
	else
		*tmp = NULL;
}

void	save_in_line_org(int idx, char *buf, char **line)
{
	char	*ltmp;

	ltmp = malloc(sizeof(char) * idx);
	*ltmp = 0;
	ft_strlcpy_g(ltmp, buf, idx);
	ft_strjoin(line, ltmp);
	free(ltmp);
}

int		save_in_line_tmp(int idx, int fd, char **tmp, char **line)
{
	char	*ttmp;
	char	*ltmp;

	ttmp = malloc(sizeof(char) * (ft_strlen(tmp[fd]) + 1));
	*ttmp = 0;
	ft_strlcpy_g(ttmp, tmp[fd], ft_strlen(tmp[fd]) + 1);
	if ((idx = check_new_line(tmp[fd], ft_strlen(tmp[fd]))))
	{
		ltmp = malloc(sizeof(char) * idx);
		*ltmp = 0;
		ft_strlcpy_g(ltmp, tmp[fd], idx);
		ft_strjoin(line, ltmp);
		free(ltmp);
		save_in_tmp(ttmp, ft_strlen(tmp[fd]), idx, &tmp[fd]);
		free(ttmp);
		return (1);
	}
	else
	{
		ft_strjoin(line, ttmp);
		free(ttmp);
		free(tmp[fd]);
		tmp[fd] = NULL;
	}
	return (0);
}

int		main_act_gnl(int fd, char *buf, char **line, char **tmp)
{
	int	idx;
	int	size;

	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == 0 || size == -1)
		{
			if (!(*line) && size == 0)
			{
				*line = malloc(sizeof(char));
				**line = 0;
			}
			free(buf);
			return (size);
		}
		if ((idx = check_new_line(buf, size)))
		{
			save_in_line_org(idx, buf, line);
			save_in_tmp(buf, size, idx, &tmp[fd]);
			free(buf);
			return (1);
		}
		save_in_line_org(size + 1, buf, line);
	}
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*tmp[1024];

	if (!(BUFFER_SIZE > 0) || fd <= -1 || fd > 65535 || !line)
		return (-1);
	if (*line != NULL)
		*line = NULL;
	if (tmp[fd] && save_in_line_tmp(0, fd, tmp, line))
		return (1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buf[BUFFER_SIZE] = 0;
	return (main_act_gnl(fd, buf, line, tmp));
}
