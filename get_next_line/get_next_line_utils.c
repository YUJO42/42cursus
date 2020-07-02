/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:30:59 by yujo              #+#    #+#             */
/*   Updated: 2020/06/30 03:11:26 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strnew(size_t size)
{
	char *str;
	size_t i;

	i = 0;
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	while (i < size)
		str[i++] = 0;
	str[size] = '\0';
	return (str);
}

void ft_strdel(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
	return;
}

char *ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (*dst && i < size)
	{
		i++;
		dst++;
	}
	while (*src && i + 1 < size)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	if (i < size)
		*dst = 0;
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	if (dst == 0)
		return (0);
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	len = 0;
	while (src[len])
		len++;
	return (len);
}
