/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:54:59 by yujo              #+#    #+#             */
/*   Updated: 2020/04/09 14:00:18 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*result;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(len);
	if (result == 0)
		return (0);
	ft_strlcpy(result, s1, len);
	ft_strlcat(result, s2, len);
	return (result);
}
