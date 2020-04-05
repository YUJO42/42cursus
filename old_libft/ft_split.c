/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 07:52:54 by yujo              #+#    #+#             */
/*   Updated: 2020/03/12 18:44:22 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	str_cmp(char ch, char c)
{
	if (ch == c)
		return (true);
	return (false);
}

void	init(char **ret, int *idx_one, int *idx_two, int len)
{
	ret[*idx_one][*idx_two] = '\0';
	(*idx_one)++;
	ret[*idx_one] = (char *)ft_calloc(len + 1, sizeof(char *));
	*idx_two = 0;
}

void 	declare(char **ret, int *idx_one, int *idx_two, int *len, char *str)
{
	*len = ft_strlen(str);
	ret = (char **)ft_calloc(*len + 1, sizeof(char *));
	*idx_one = 0;
	*idx_two = 0;
	ret[*idx_one] = (char *)ft_calloc(*len + 1, sizeof(char));
}

char	**ft_split(char const *str, char c)
{
	char	**ret;
	int		len;
	int		i;
	int		idx_one;
	int		idx_two;

	ret = 0;
	declare(ret, &idx_one, &idx_two, &len, (char *)str);
	i = -1;
	while (str[++i])
	{
		if (!str_cmp(str[i], c))
			ret[idx_one][idx_two++] = str[i];
		else if (idx_two == 0)
			continue;
		else
			init(ret, &idx_one, &idx_two, len);
	}
	if (idx_one != 0 && str[len - 1] != c)
		init(ret, &idx_one, &idx_two, len);
	if (idx_two != 0 && idx_one == 0)
		ret[idx_one + 1] = 0;
	else ret[idx_one] = 0;
	return (ret);
}
