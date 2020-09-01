/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:16:53 by yujo              #+#    #+#             */
/*   Updated: 2020/04/09 16:52:22 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlelen;

	needlelen = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)stack);
	i = 0;
	while (i < len && stack[i])
	{
		if (ft_strncmp(&stack[i], needle, needlelen) == 0
				&& i + needlelen <= len)
			return ((char *)(&stack[i]));
		i++;
	}
	return (0);
}
