/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:31:02 by yujo              #+#    #+#             */
/*   Updated: 2020/06/30 02:34:22 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 8
#endif

char *ft_strnew(size_t size);
void ft_strdel(char **str);
char *ft_strchr(const char *s, int c);
size_t ft_strlcat(char *dst, const char *src, size_t size);
size_t ft_strlcpy(char *dst, const char *src, size_t size);

char *ft_strsub(char const *s, unsigned int start, size_t len);
char *ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
int ft_new_line(char **save_line, char **line, int fd, int ret);
int get_next_line(int fd, char **line);

#endif