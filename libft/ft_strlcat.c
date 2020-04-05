/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 09:53:09 by yujo              #+#    #+#             */
/*   Updated: 2020/03/23 10:08:24 by yujo             ###   ########.fr       */
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

/*
int main(void)
{
	char dst1[10] = "Hello, ";
	char dst2[10] = "Hello, ";
	char *src = "strlcat";

	printf("%zu\n", strlcat(dst1, src, 20));
	printf("%zu\n", ft_strlcat(dst2, src, 20));

	printf("strlcat : %s\n", dst1);
	printf("ft_strlcat : %s\n", dst2);
	
	return 0;
}
*/
