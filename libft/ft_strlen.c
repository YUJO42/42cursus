/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 20:11:42 by yujo              #+#    #+#             */
/*   Updated: 2020/03/21 20:15:38 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
int main(void)
{
	char *str = "Hello, My New lib!";

	printf("strlen : %lu\n", strlen(str));
	printf("ft_strlen : %lu\n", ft_strlen(str));
}
*/
