/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:14:06 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_c(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

void	init_index(char const *s, char c, int *index)
{
	int	idx;

	idx = 0;
	*index = -1;
	index++;
	while (*(s + idx))
	{
		if (*(s + idx) == c)
		{
			*index = idx;
			index++;
		}
		idx++;
	}
	*index = idx;
}

int		alloc_ans2(int size, int *index, char **ans, const char *s)
{
	int idx;
	int idxt;
	int	idxf;

	idx = 0;
	idxf = 0;
	while (idx + 1 < size + 2)
	{
		idxt = *(index + idx + 1) - *(index + idx);
		if (idxt > 1)
		{
			if (!(ans[idxf] = ft_substr(s, *(index + idx) + 1, idxt - 1)))
			{
				while (idxf--)
					free(ans[idxf]);
				free(ans);
				return (0);
			}
			idxf++;
		}
		idx++;
	}
	ans[idxf] = 0;
	return (1);
}

char	**alloc_ans(char const *s, char c, int *index)
{
	int		idx;
	int		size;
	int		count;
	char	**ans;

	idx = 0;
	size = find_c(s, c);
	count = 0;
	while (idx + 1 < size + 2)
	{
		if (*(index + idx + 1) - *(index + idx) > 1)
			count++;
		idx++;
	}
	if (!(ans = malloc(sizeof(char*) * (count + 1))))
	{
		free(index);
		return (0);
	}
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	int		*index;
	char	**ans;

	if (!s || !(index = malloc(sizeof(int) * (find_c(s, c) + 2))))
		return (0);
	init_index(s, c, index);
	if (!(ans = alloc_ans(s, c, index)))
		return (0);
	if (!alloc_ans2(find_c(s, c), index, ans, s))
	{
		free(index);
		return (0);
	}
	free(index);
	return (ans);
}
