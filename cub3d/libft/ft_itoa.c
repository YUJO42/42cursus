/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:12:55 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		set_size(unsigned int n)
{
	long long	div;
	int			size;

	size = 1;
	div = 10;
	while (n / div > 0)
	{
		div *= 10;
		size++;
	}
	return (size);
}

void	init_ans(unsigned int num, char *ans, int size)
{
	*(ans + size) = 0;
	if (num == 0)
		*ans = '0';
	else
	{
		size--;
		while (size >= 0 && (num % 10 || num / 10))
		{
			*(ans + size) = num % 10 + '0';
			size--;
			num = num / 10;
		}
	}
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				size;
	char			*ans;

	size = 0;
	if (n < 0)
	{
		size++;
		num = -(unsigned int)n;
	}
	else
		num = (unsigned int)n;
	if (num == 0)
		size = 1;
	else
		size += set_size(num);
	ans = malloc(sizeof(char) * (size + 1));
	if (ans == 0)
		return (0);
	init_ans(num, ans, size);
	if (n < 0)
		*ans = '-';
	return (ans);
}
