/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:16:29 by yujo              #+#    #+#             */
/*   Updated: 2020/03/23 10:20:06 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ret = (char *)s;
		s++;
	}
	if (*s == (char)c)
		ret = (char *)s;
	return (ret);
}

/*
int main(void)
{
	char *s = "Hello, strchr";

	printf("strrchr : %s\n", strrchr(s, 111));
	printf("ft_strrchr : %s\n", ft_strrchr(s, 111));

	return 0;
}
*/
