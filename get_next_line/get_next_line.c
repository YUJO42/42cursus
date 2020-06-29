/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:31:03 by yujo              #+#    #+#             */
/*   Updated: 2020/06/30 03:07:42 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	len2;
	char	*result;

	len = 0;
	len2 = 0;
	while (s1[len])
		len++;
	while (s2[len2])
		len2++;
	len += (len2 + 1);
	result = malloc(len);
	if (result == 0)
		return (0);
	ft_strlcpy(result, s1, len);
	ft_strlcat(result, s2, len);
	return (result);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*result;

	len = 0; 
    while (s[len])
        len++;
	if (!(result = malloc(len + 1)))
		return (0);
	i = 0;
	while (len)
	{
		result[i] = *s++;
		len--;
		i++;
	}
	result[i] = '\0';
	return (result);
}

int     ft_new_line(char **save_line, char **line, int fd, int ret)
{
    char    *temp;
    int     len;

    len = 0;
    while (save_line[fd][len] != '\n' && save_line[fd][len] != '\0')
        len++;
    if (save_line[fd][len] == '\n')
    {
        *line = ft_strsub(save_line[fd], 0, len);
        temp = ft_strdup(save_line[fd] + len + 1);
        free(save_line[fd]);
        save_line[fd] = temp;
        if (save_line[fd][0] == '\0')
            ft_strdel(&save_line[fd]);
    }
    else if (save_line[fd][len] == '\0')
    {
        if (ret == BUFFER_SIZE)
            return (get_next_line(fd, line));
        *line = ft_strdup(save_line[fd]);
        ft_strdel(&save_line[fd]);
    }
    return (1);
}

int     get_next_line(int fd, char **line)
{
    static char *save_line[OPEN_MAX];
    char        buffer[BUFFER_SIZE + 1];
    char        *temp;
    int         ret;

    if (fd < 0 || line == NULL)
        return (-1);
    while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[ret] = '\0';
        if (save_line[fd] == NULL)
            save_line[fd] = ft_strnew(1);
        temp = ft_strjoin(save_line[fd], buffer);
        free(save_line[fd]);
        save_line[fd] = temp;
        if (ft_strchr(buffer, '\n'))
            break;
    }
    
    if (ret < 0)
        return (-1);
    else if (ret == 0 && (save_line[fd] || save_line[fd][0] == '\0'))
        return (0);
    return (ft_new_line(save_line, line, fd, ret));
}
