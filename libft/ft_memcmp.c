/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 17:33:34 by yujo              #+#    #+#             */
/*   Updated: 2020/03/21 19:49:56 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if (n == 0)
		return (0);

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;

	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i == n)
		i--;
	if (str1[i] == str2[i])
		return (0);
	return (str1[i] - str2[i]);
}

/*

int main(void)
{
	char *str1 = "hello my libft";
	char *str2 = "hello my libfT";
	
	char *str3 = "test";
	char *str4 = "tEst";

	printf("memcmp : %d\n", memcmp(str1, str2, 20));
	printf("ft_memcmp : %d\n", ft_memcmp(str1, str2, 20));
	printf("memcmp : %d\n", memcmp(str1, str2, 5));
	printf("ft_memcmp : %d\n", ft_memcmp(str1, str2, 5));
	printf("memcmp : %d\n", memcmp(str3, str4, 5)); 	  // output : 1
	printf("ft_memcmp : %d\n", ft_memcmp(str3, str4, 5)); // output : 32; <--- check하기
}

*/
