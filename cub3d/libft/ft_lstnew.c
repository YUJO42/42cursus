/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:13:01 by yujo              #+#    #+#             */
/*   Updated: 2020/03/04 14:19:41 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (0);
	ret->content = content;
	ret->next = 0;
	return (ret);
}
