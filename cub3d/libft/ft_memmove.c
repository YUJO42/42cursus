/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:13:40 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	index;

	if (dest == 0 && src == 0)
		return (0);
	if (dest <= src)
	{
		index = 0;
		while (index < n)
		{
			*(char*)(dest + index) = *(char*)src;
			src++;
			index++;
		}
	}
	else
	{
		index = n;
		while (index != 0)
		{
			*(char*)(dest + index - 1) = *(char*)(src + index - 1);
			index--;
		}
	}
	return (dest);
}
