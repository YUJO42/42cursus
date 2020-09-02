/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:11:05 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	unsigned int	ans;
	int				mchk;

	mchk = 0;
	if (*nptr == 0)
		return (0);
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\r'
			|| *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr != '+' && *nptr != '-' && (*nptr < '0' || *nptr > '9'))
		return (0);
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			mchk++;
		nptr++;
	}
	ans = 0;
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
		ans = ans * 10 + *(nptr++) - '0';
	if (mchk == 1)
		return (-ans);
	return (ans);
}
