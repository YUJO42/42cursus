/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 07:52:54 by yujo              #+#    #+#             */
/*   Updated: 2020/04/10 23:02:12 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, char c)
{
	int		count;

	count = 0;
	if (*s == 0 && c == 0)
		return (0);
	while (*s == c)
		s++;
	s--;
	while (*++s)
		if (*s != c && (*(s + 1) == c || (!(*(s + 1)))))
			count++;
	return (count);
}

static int	mapping(char *s, char **ret, char c)
{
	int		i;
	int		j;

	j = 0;
	if (*s == 0 && c == 0)
		return (0);
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (s[i] != c && s[i])
				i++;
			if (!(ret[j] = (char *)malloc(sizeof(char) * (i + 1))))
				return (-1);
			ft_strlcpy(ret[j++], s, i + 1);
			s = s + i;
		}
		else
			s++;
	}
	return (0);
}

char		**ft_split(char const *s, char c)
{
	int		count;
	char	*cp;
	char	**ret;

	cp = (char *)s;
	count = count_word(cp, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	ret[count] = 0;
	if (mapping(cp, ret, c) == -1)
		return (0);
	return (ret);
}
