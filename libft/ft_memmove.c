/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 15:47:28 by yujo              #+#    #+#             */
/*   Updated: 2020/03/21 16:46:26 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char temp[n];

	ft_memcpy(temp, src, n);
	ft_memcpy(dest, temp, n);
	return (dest);
}

/*
int main(void)
{
	char dest1[20];
	char dest2[20];
	char *src = "memmove test";
	
	printf("memmove : %s\n", memmove(dest1, src, 15));
	printf("ft_memmove : %s\n", ft_memmove(dest1, src, 15));
}
*/
