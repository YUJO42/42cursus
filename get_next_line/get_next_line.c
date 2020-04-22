/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 14:28:58 by yujo              #+#    #+#             */
/*   Updated: 2020/04/21 14:44:07 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static	_static[1024]; //OPEN_MAX
	char	*_buffer;
	int		byte;
	char	*temp;
	char	*next_line_index;

	if (fd < 0 || 
}
