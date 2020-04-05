/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 15:27:08 by yujo              #+#    #+#             */
/*   Updated: 2020/03/21 15:43:20 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	i = 0;

	while  (i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);

}
/*
int main(void)
{
	char dest1[20];
	char dest2[20];
	char dest3[20];
	char dest4[20];
	char *src = "Hello, a LIBFT";

	int test1 = memccpy(dest1, src, 1, 5);
	printf("ft_memccpy[5] : %c\n", ft_memccpy(dest2, src, 'a', 5));
	printf("memccpy[10] : %c\n", memccpy(dest3, src, 'a', 10));
	printf("ft_memccpy[10] : %\n", ft_memccpy(dest4, src, 'a', 10));
}
 @@@@@@@ 테케 다시 체크하기
*/
