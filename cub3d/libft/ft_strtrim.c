/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:14:50 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	find_len(char const *s1, char const *set)
{
	size_t	len;
	int		ok;
	int		index;

	len = ft_strlen(s1);
	ok = 1;
	while (ok && len > 0)
	{
		index = 0;
		while (*(set + index))
		{
			if (*(set + index) == *(s1 + len - 1))
				break ;
			index++;
		}
		if (*(set + index) != *(s1 + len - 1))
			ok = 0;
		else
			len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		ok;
	char	*tmp;
	int		index;

	len = find_len(s1, set);
	ok = 1;
	while (ok && len > 0)
	{
		index = -1;
		while (*(set + ++index))
		{
			if (*(set + index) == *s1)
				break ;
		}
		if (*(set + index) != *s1)
			ok = 0;
		else
		{
			s1++;
			len--;
		}
	}
	tmp = ft_substr(s1, 0, len);
	return (tmp);
}
