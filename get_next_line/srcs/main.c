/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:17:19 by yujo              #+#    #+#             */
/*   Updated: 2020/04/19 18:17:22 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line;
	int		ret;
	int		fd;

	fd = open("test", O_RDONLY);
//	fd = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("get_next_line : %s\n", line);
		printf("return value : %d\n\n", ret);
		free(line);
	}
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n", ret);
	free(line);
	return (0);
}
