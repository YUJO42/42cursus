/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:26:46 by yujo              #+#    #+#             */
/*   Updated: 2020/03/05 01:42:23 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_intlen(int n)
{
    int     cnt;
    cnt = n == 0 ? 1 : 0;
    while (n != 0)
	{
		n /= 10;
        cnt++;
    }
    return (cnt);
}
char    *ft_itoa(int n)
{
    char    *dest;
	int     len;
	long    num;
	
	num = n < 0 ? -1 * (long)n : n;
	len = n < 0 ? ft_intlen(num) + 1 : ft_intlen(num);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	dest[len] = 0;
	while (len > 0)
	{
		dest[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
