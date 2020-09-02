/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:53:42 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 16:53:44 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy_g(char *dst, const char *src, size_t size);

void	ft_strjoin(char **s1, char const *s2);

int		check_new_line(char *buf, int size);

int		get_next_line(int fd, char **line);

#	endif
