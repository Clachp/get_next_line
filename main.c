/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:44:53 by cchapon           #+#    #+#             */
/*   Updated: 2022/06/13 16:21:16 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int     fd;
    int     fd2;
    char    *line;
   //char *line2;
    //char *line3;

    fd = open("poeme.txt", O_RDONLY);
    fd2 = open("lorem.txt", O_RDONLY);
	line = get_next_line(fd);
    /*printf("line 1 : -%s-\n", line);
    free(line);
    line2 = get_next_line(fd);
    printf("line2 : -%s-\n", line2);
    free(line2);
    line3 = get_next_line(fd);
    printf("line3 : -%s-\n", line3);
    free(line3);*/
    while (line)
    {
        printf("%s", line);
        free (line);
        line = get_next_line(fd);
        printf("%s", line);
        free (line);
        line = get_next_line(fd2);
    }
    close(fd);
    close(fd2); 
    return (0);
}