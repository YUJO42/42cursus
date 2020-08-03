/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:23:29 by yujo              #+#    #+#             */
/*   Updated: 2020/08/03 22:56:25 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include <stdio.h>

# include <stdio.h>

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>

# define FORMAT "cspdiuxX%"

typedef struct	s_struct
{
	int			count;
}				t_struct;

#endif
