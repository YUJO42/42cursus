/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:14:16 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	olen;
	size_t	tlen;
	char	*tmp;
	size_t	index;

	index = 0;
	olen = ft_strlen(s1);
	tlen = ft_strlen(s2);
	tmp = malloc(sizeof(char) * (olen + tlen + 1));
	if (tmp == 0)
		return (0);
	while (index < olen)
		*(tmp + index++) = *(s1++);
	while (index < olen + tlen)
		*(tmp + index++) = *(s2++);
	*(tmp + index) = 0;
	return (tmp);
}
