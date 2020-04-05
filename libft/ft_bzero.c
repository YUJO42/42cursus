/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 12:33:49 by yujo              #+#    #+#             */
/*   Updated: 2020/03/21 13:05:42 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
int main(void)
{
	char arr1[20];
	char arr2[20];

	ft_memset(arr1, 42, sizeof(arr1));
	ft_memset(arr2, 42, sizeof(arr2));

	bzero(arr1, sizeof(arr1));
	ft_bzero(arr2, sizeof(arr1));

	for (int i = 0; i < 20; i++)
		printf("bzero : %c ft_bzero : %c\n", arr1[i], arr2[i]);
}
*/
