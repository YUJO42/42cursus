/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:46:35 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 15:31:06 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == 0)
		return (0);
	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

size_t	ft_strlcpy_g(char *dst, const char *src, size_t size)
{
	int		len;
	size_t	count;

	len = ft_strlen(src);
	count = 0;
	while (*src && count < size - 1 && size != 0)
	{
		*dst = *src;
		dst++;
		src++;
		count++;
	}
	if (size != 0)
		*dst = 0;
	return (len);
}

void	ft_strjoin(char **s1, char const *s2)
{
	size_t	olen;
	size_t	tlen;
	char	*tmp;
	size_t	index;

	index = 0;
	olen = 0;
	if (*s1)
		olen = ft_strlen(*s1);
	tlen = ft_strlen(s2);
	tmp = malloc(sizeof(char) * (olen + tlen + 1));
	if (tmp == 0)
		return ;
	while (index < olen)
	{
		*(tmp + index) = s1[0][index];
		index++;
	}
	while (index < olen + tlen)
		*(tmp + index++) = *(s2++);
	*(tmp + index) = 0;
	free(*s1);
	*s1 = NULL;
	*s1 = tmp;
}

int		check_new_line(char *buf, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (buf[idx] == '\n')
			return (idx + 1);
		idx++;
	}
	return (0);
}
