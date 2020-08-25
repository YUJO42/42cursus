/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:31:03 by yujo              #+#    #+#             */
/*   Updated: 2020/08/25 14:59:26 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	size;
	size_t	i;
	size_t	j;

	size = (size_t)(ft_strlen((char *)s1)) + (size_t)(ft_strlen((char *)s2));
	if (!(res = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
		res[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] != '\0')
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

size_t			ft_strlen(const char *s)
{
	size_t	n;
	char	*t;

	if (!s)
		return (0);
	n = 0;
	t = (char*)s;
	while (*(t++))
		n++;
	return (n);
}

char			*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*dup;

	size = -1;
	while (s1[++size])
		;
	if (!(dup = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}