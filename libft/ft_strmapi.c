/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 07:26:17 by yujo              #+#    #+#             */
/*   Updated: 2020/03/24 07:28:31 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (0);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, result[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
