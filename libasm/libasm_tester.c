/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 08:50:15 by yujo              #+#    #+#             */
/*   Updated: 2020/09/09 13:30:10 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libasm.h"

void    ft_strlen_test()
{
    char *a = " -asdqwe1szc,m.nadsf     ";
    char *b = "";
    char *c = "         yujo";

    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@          ft_stlren           @\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
    
    printf("strlen    : %lu\n", strlen(a));
    printf("ft_strlen : %lu\n", strlen(a));
    printf("--------------------------------\n");
    
    printf("strlen    : %lu\n", strlen(b));
    printf("ft_strlen : %lu\n", strlen(b));
    printf("--------------------------------\n");

    printf("strlen    : %lu\n", strlen(c));
    printf("ft_strlen : %lu\n", strlen(c));
    printf("--------------------------------\n");
    return;
}

void    ft_strcpy_test()
{
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@          ft_strcpy           @\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");

    char *a = " -asdqwe1szc,m.nadsf     ";
    char *b = "";
    char *c = "         yujo";

    char dest1[strlen(a) + 1];
    char dest2[strlen(b) + 1];
    char dest3[strlen(c) + 1];

    char ft_dest1[strlen(a) + 1];
    char ft_dest2[strlen(b) + 1];
    char ft_dest3[strlen(c) + 1];

    printf("strcpy    : %s\n", strcpy(dest1, a));
    printf("ft_strcpy : %s\n", ft_strcpy(ft_dest1, a));
    printf("--------------------------------\n");

    printf("strcpy    : %s\n", strcpy(dest2, b));
    printf("ft_strcpy : %s\n", ft_strcpy(ft_dest2, b));
    printf("--------------------------------\n");

    printf("strcpy    : %s\n", strcpy(dest3, c));
    printf("ft_strcpy : %s\n", ft_strcpy(ft_dest3, c));
    printf("--------------------------------\n");

    return;
}

void    ft_strcmp_test()
{
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@          ft_strcmp           @\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");

    printf("strcmp    : %d\n", strcmp("asdqwe", ""));
    printf("ft_strcmp : %d\n", ft_strcmp("asdqwe", ""));
    printf("--------------------------------\n");

    return;
}

void    ft_strdup_test()
{
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@          ft_strdup           @\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");

    char *a = " -asdqwe1szc,m.nadsf     ";
    char *b = "";
    char *c = "         yujo";

    char *dest1 = strdup(a);
    char *dest2 = strdup(b);
    char *dest3 = strdup(c);

    char *ft_dest1 = ft_strdup(a);
    char *ft_dest2 = ft_strdup(b);
    char *ft_dest3 = ft_strdup(c);

    printf("strdup    : %s\n", dest1);
    printf("ft_strdup : %s\n", ft_dest1);
    printf("--------------------------------\n");

    printf("strdup    : %s\n", dest2);
    printf("ft_strdup : %s\n", ft_dest2);
    printf("--------------------------------\n");

    printf("strdup    : %s\n", dest3);
    printf("ft_strdup : %s\n", ft_dest3);
    printf("--------------------------------\n");

    free(dest1);
    free(dest2);
    free(dest3);
    free(ft_dest1);
    free(ft_dest2);
    free(ft_dest3);

    return;
}

void    ft_read_test()
{
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@           ft_read            @\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");

    int		fd1;
	int		fd2;
	char	line1[1024];
	char	line2[1024];

	fd1 = open("./test.txt", O_RDONLY);
	fd2 = open("./test.txt", O_RDONLY);
    
	printf("read     : %ld\n", read(fd1, line1, 1024));
	printf("ft_read	 : %ld\n", read(fd2, line2, 1024));
    printf("--------------------------------\n");

	printf("read     : %s\n", line1);
	printf("ft_read	 : %s\n", line2);
    
    return;
}
void    ft_write_test()
{
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@           ft_write           @\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");

    char *a1 = "write    : -asdqwe1szc,m.nadsf    \n";
    char *a2 = "ft_write : -asdqwe1szc,m.nadsf    \n";

    char *line = "--------------------------------\n";

    char *b1 = "write    :         yujo\n";
    char *b2 = "ft_write :         yujo\n";
    
    write(1, a1, strlen(a1));
    write(1, a2, strlen(a2));
    write(1, line, strlen(line));
    write(1, b1, strlen(b1));
    write(1, b2, strlen(b2));

    return ;
}

int     main(void)
{   
    ft_strlen_test();
    ft_strcpy_test();
    ft_strcmp_test();
    ft_strdup_test();
    ft_read_test();
    ft_write_test();
    return (0);
}