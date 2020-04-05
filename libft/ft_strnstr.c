/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:24:26 by yujo              #+#    #+#             */
/*   Updated: 2020/03/23 14:01:13 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char			*t_str;
	char			*t_to_find;
	unsigned int	i;
	unsigned int	llen;

	if (*little == '\0')
		return ((char *)(big));
	llen = ft_strlen(little);
	i = 0;
	while (i + llen <= len)
	{
		t_str = (char *)big + i;
		t_to_find = (char *)little;
		while (*t_str == *t_to_find && *t_to_find != '\0')
		{
			t_to_find++;
			t_str++;
		}
		if (*t_to_find == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}

/*
int main(void)
{
	char *str1 = "Hello, World";
	char *str2 = "Wor";
	char *str3 = "asd";

	printf("strnstr : %s\n", strnstr(str1, str2, 20));
	printf("ft_strnstr : %s\n", ft_strnstr(str1, str2, 20));
	printf("strnstr : %s\n", strnstr(str1, str3, 20));
	printf("ft_strnstr : %s\n", ft_strnstr(str1, str3, 20));

	return 0;
}
*/
