/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:14:30 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*ans;

	index = 0;
	ans = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ans == 0)
		return (0);
	*(ans + ft_strlen(s)) = 0;
	while (index < ft_strlen(s))
	{
		*(ans + index) = f(index, *(s + index));
		index++;
	}
	return (ans);
}
