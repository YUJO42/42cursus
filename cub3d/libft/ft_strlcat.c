/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:28:10 by yujo              #+#    #+#             */
/*   Updated: 2020/04/22 15:49:11 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

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
