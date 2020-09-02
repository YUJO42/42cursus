/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:14:54 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*tmp;

	index = 0;
	if (s == 0)
		return (0);
	if (!(tmp = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start > ft_strlen(s))
	{
		tmp[0] = 0;
		return (tmp);
	}
	while (index < len && s[start + index])
	{
		*(tmp + index) = *(s + start + index);
		index++;
	}
	*(tmp + index) = 0;
	return (tmp);
}
