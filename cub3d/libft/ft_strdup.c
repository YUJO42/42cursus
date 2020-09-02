/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:14:12 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	index;

	index = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (tmp == 0)
		return (0);
	while (index < ft_strlen(s))
	{
		*(tmp + index) = *(s + index);
		index++;
	}
	*(tmp + index) = 0;
	return (tmp);
}
