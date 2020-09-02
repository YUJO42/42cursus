/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:57:24 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 09:03:41 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_HEADER
# define CUB3D_HEADER

# include "./utils/utils.h"

# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef struct	s_info
{
	int		*floor;
	int		*res;
	int		*ceilling;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int		map_width;
	int		map_height;
	char	**map;
}				t_info;

void			exit_with_errmsg(char *errmsg);
int				check_screenshot_option(int argc, char *option_str);

#endif