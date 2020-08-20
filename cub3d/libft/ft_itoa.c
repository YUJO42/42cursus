/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:26:46 by yujo              #+#    #+#             */
/*   Updated: 2020/04/07 17:56:15 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_itoa(int n)
{
	int			cnt;
	char		*rtn;
	long long	temp;

	temp = n;
	if ((cnt = 1) == 1 && temp < 0)
		cnt++;
	if (temp < 0)
		temp *= -1;
	while ((temp = temp / 10) > 0)
		cnt++;
	if ((rtn = (char *)malloc(sizeof(char) * (cnt + 1))) == 0)
		return (0);
	temp = (long long)n * 10;
	if (temp < 0)
	{
		rtn[0] = '-';
		temp *= -1;
	}
	rtn[cnt--] = '\0';
	if (temp == 0)
		rtn[cnt] = '0';
	while ((temp = temp / 10) > 0)
		rtn[cnt--] = temp % 10 + '0';
	return (rtn);
}
