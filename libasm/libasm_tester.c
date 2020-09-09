/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 08:50:15 by yujo              #+#    #+#             */
/*   Updated: 2020/09/09 10:46:14 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libasm.h"

void    ft_strlen_test()
{
    char *a = " -asdqwe1sdxzc,m.nadsf     ";
    char *b = "";
    char *c = "         yujo";

    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@           ft_stlren          @\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
    
    printf("strlen    : %lu\n", strlen(a));
    printf("ft_strlen : %lu\n\n", strlen(a));
    printf("strlen    : %lu\n", strlen(b));
    printf("ft_strlen : %lu\n\n", strlen(b));
    printf("strlen    : %lu\n", strlen(c));
    printf("ft_strlen : %lu\n", strlen(c));

    return;
}

void    ft_read_test()
{
    //
}

int     main(void)
{   
    ft_strlen_test();
    return (0);
}