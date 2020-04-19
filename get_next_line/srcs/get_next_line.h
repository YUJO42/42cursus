/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 14:29:06 by yujo              #+#    #+#             */
/*   Updated: 2020/04/19 18:14:32 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define NL 1
# define _EOF 0
# define ERROR -1

int		get_next_line(int fd, char **line);

char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *c);
char	*ft_strcpy(char *dst, char *stc, size_t n);
char	*ft_strndup(char *s1, size_t size);
char	*ft_strjoin(char *s1, char *s2);

#endif
