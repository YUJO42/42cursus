/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 20:15:55 by yujo              #+#    #+#             */
/*   Updated: 2020/03/23 09:26:40 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (!size)
	{
		while (dst[i])
			i++;
	}
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}
/*
int main(void)
{
	char dst1[20];
	char dst2[20];
	char *src = "Hello strlcpy!";

	strlcpy(dst1, src, 15);
	ft_strlcpy(dst2, src, 15);

	printf("strlcpy : %s\n", dst1);
	printf("ft_strlcpy : %s\n", dst2);
	
	return 0;
}
*/
