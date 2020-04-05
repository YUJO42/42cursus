/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:37:11 by yujo              #+#    #+#             */
/*   Updated: 2020/03/23 13:57:04 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*

int main(void)
{
	char *str1 = "Hello, strncmp";
	char *str2 = "Hello, Strncmp";
	char *str3 = "Hello, strncmp";

	printf("strncmp : %d\n", strncmp(str1, str2, 20));
	printf("ft_strncmp : %d\n", ft_strncmp(str1, str2, 20));
	printf("strncmp : %d\n", strncmp(str1, str3, 20));
	printf("ft_strncmp : %d\n", ft_strncmp(str1, str3, 20));
}
*/
