/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:28:01 by yujo              #+#    #+#             */
/*   Updated: 2020/02/28 15:18:38 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *arr1;
	unsigned char *arr2;

	if (n == 0)
		return (0);
	arr1 = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	while ((*arr1 == *arr2) && n - 1 > 0)
	{
		arr1++;
		arr2++;
		n--;
	}
	return (*arr1 - *arr2);
}
