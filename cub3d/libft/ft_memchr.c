/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:13:30 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	idx;
	unsigned char	tmp;
	unsigned char	*tms;

	tms = (unsigned char*)s;
	idx = 0;
	tmp = (unsigned char)c;
	while (idx < n)
	{
		if (*tms == tmp)
			return (tms);
		tms++;
		idx++;
	}
	return (0);
}
