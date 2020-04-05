/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:20:43 by yujo              #+#    #+#             */
/*   Updated: 2020/02/28 16:51:53 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int	start, size_t len)
{
	char	*result;

	if (!(result = malloc(++len)))
		return (0);
	ft_strlcpy(result, s + start, len);
	return (result);
}
