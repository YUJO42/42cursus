/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 16:54:52 by yujo              #+#    #+#             */
/*   Updated: 2020/03/21 17:32:12 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	unsigned char *str;
	unsigned char find;

	str = (unsigned char *)s;
	find = (unsigned char)c;

	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}

/*
int main(void)
{
	char str1[20] = "Hello, 1 Han";
	char str2[20] = "Hello, 1 Han";
	
	printf("memchr : %s\n", memchr(str1, 49, 10));
	printf("ft_memchr : %s\n", ft_memchr(str2, 49, 10));

	return 0;
}
*/
