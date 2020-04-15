/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 09:31:56 by yujo              #+#    #+#             */
/*   Updated: 2020/04/15 09:35:00 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 10
# endif

# define NL 1
# define _EOF 0
# define ERROR -1

int		get_next_line(int fd, char **line);

char	*ft_strchr(char *s, int c);
char	*ft_strcpy(char *dst, char *src, size_t n);
char	*ft_strndup(char *s1, size_t size);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *c);

#endif
