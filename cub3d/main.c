/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:30:30 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 09:03:44 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_screenshot_option(int argc, char *option_str)
{
	if (argc == 3 && !ft_strncmp("--save", option_str, 6))
		return (TRUE);
	else
		return (FALSE);
}

void	exit_with_errmsg(char *errmsg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(errmsg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(1);
}

int     main(int argc, char **argv)
{
    t_info      game_info;
    int         check_capture;       

    if (argc == 1)
        exit_with_errmsg("please enter a argument");
    else if (3 < argc)
        exit_with_errmsg("please enter '1' or '2' argument");
    check_capture = check_screenshot_option(argc, argv[2]);
}