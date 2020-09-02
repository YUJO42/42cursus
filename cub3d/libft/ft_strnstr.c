/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:14:37 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	unsigned int	tidx;
	unsigned int	index;
	const char		*tmp;

	if (*lit == 0)
		return ((char*)big);
	index = -1;
	while (++index < len)
	{
		if (*(big + index) == *lit)
		{
			tidx = index;
			tmp = lit;
			while (*tmp && tidx < len && *tmp == *(big + tidx))
			{
				tmp++;
				tidx++;
			}
			if (*tmp == 0)
				return ((char*)(big + index));
		}
	}
	return (0);
}
