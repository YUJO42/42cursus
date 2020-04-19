/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 14:31:38 by yujo              #+#    #+#             */
/*   Updated: 2020/04/19 14:56:11 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

#define MAX 1000

int main(void)
{
	int fd;
	char buf1[MAX];

	if ((fd = open("ex01.txt", O_RDONLY)) == -1)
	{
		perror("failed");
		exit(1);
	}

	read(fd, buf1, MAX);

	for (int i = 0; i < MAX; i++)
		printf("%c", buf1[i]);

	close(fd);
	exit(0);
}
