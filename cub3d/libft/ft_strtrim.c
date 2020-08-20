/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:19:05 by yujo              #+#    #+#             */
/*   Updated: 2020/04/07 17:51:09 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_set(char a, char const *set)
{
	while (*set)
	{
		if (a == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*first;
	char	*last;
	char	*result;
	size_t	len;

	first = (char *)s1;
	last = first + ft_strlen(s1);
	while (*first && check_set(*first, set))
		first++;
	while (first < last && check_set(*(last - 1), set))
		last--;
	len = last - first + 1;
	if (!(result = malloc(len)))
		return (0);
	ft_strlcpy(result, first, len);
	return (result);
}
