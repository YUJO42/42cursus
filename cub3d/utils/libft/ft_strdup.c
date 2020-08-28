/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/04/09 14:11:49 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*result;

	len = ft_strlen(s);
	if (!(result = malloc(len + 1)))
		return (0);
	i = 0;
	while (len)
	{
		result[i] = *s++;
		len--;
		i++;
	}
	result[i] = '\0';
	return (result);
}
