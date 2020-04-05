/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 13:06:27 by yujo              #+#    #+#             */
/*   Updated: 2020/03/21 15:33:29 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	
	if (!n || dest == src)
		return (dest);

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	i = 0;

	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}

	return (dest);
}
/*
int main(void)
{
	char dest1[20];
	char dest2[20];
	char dest3[20];
	char dest4[20];
	char *src = "Hello, LIBFT";

	printf("memcpy[5] : %s\n", memcpy(dest1, src, 5));
	printf("ft_memcpy[5] : %s\n", ft_memcpy(dest2, src, 5));
	printf("memcpy[10] : %s\n", memcpy(dest3, src, 10));
	printf("ft_memcpy[10] : %s\n", ft_memcpy(dest4, src, 10));
}

출력값
memcpy[5] : Hello
ft_memcpy[5] : Hello
memcpy[10] : Hello, LIBIQ      @@ memcpy는 빈 공간에 쓰레기값 처리안됨
ft_memcpy[10] : Hello, LIB	   @@ ft_memcpy는 됨 // 나중에 찾아보기

*/
