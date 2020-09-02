/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:13:17 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*tmp;
	t_list	*tmp2;

	tmp = lst;
	ans = NULL;
	while (tmp)
	{
		tmp2 = ft_lstnew(f(tmp->content));
		if (tmp2 == 0)
		{
			ft_lstclear(&ans, del);
			return (0);
		}
		ft_lstadd_back(&ans, tmp2);
		tmp = tmp->next;
	}
	return (ans);
}
