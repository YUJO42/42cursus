/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:10:08 by yujo              #+#    #+#             */
/*   Updated: 2020/03/23 10:16:05 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char*)s);
}

/*
int main(void)
{
	char *s = "Hello, strchr";

	printf("strchr : %s\n", strchr(s, 111));
	printf("ft_strchr : %s\n", ft_strchr(s, 111));
}
*/
