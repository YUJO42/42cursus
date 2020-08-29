/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:57:24 by yujo              #+#    #+#             */
/*   Updated: 2020/08/29 16:05:19 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_HEADER
# define CUB3D_HEADER

# include "../utils/keymap.h"
# include "../utils/libft/libft.h"
# include "../utils/mlx_beta/mlx.h"
# include "../utils/gnl/get_next_line.h"

# include <math.h>
# include <fcntl.h>

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