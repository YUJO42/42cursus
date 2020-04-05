/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:47:53 by yujo              #+#    #+#             */
/*   Updated: 2020/03/21 15:12:03 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		*(str++) = (unsigned char)c;
		n--;
	}
	return (s);
}
/*
int main(void)
{
	char arr1[20];
	char arr2[20];

	memset(arr1, 42, sizeof(arr1));
	ft_memset(arr2, 42, sizeof(arr2));

	for (int i = 0; i < 20; i++)
	{
		printf("memset : %c\n", arr1[i]);
		printf("ft_memset : %c\n", arr2[i]);
	}

	return 0;
}
*/
