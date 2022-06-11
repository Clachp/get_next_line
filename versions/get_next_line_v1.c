/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:32:48 by cchapon           #+#    #+#             */
/*   Updated: 2022/06/09 18:03:51 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stock;
	char			*line;
	char			*buff;
	int				r;
	int				n;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!stock)
	{
		stock = malloc(1);
		stock[0] = '\0';
	}
	r = 1;
	while (r)
	{
		r = read(fd, buff, BUFFER_SIZE);
		buff[r] = '\0';
		stock = ft_strjoin(stock, buff);
		n = to_end(stock);
		if (n >= 0) // ici r != 0 on est dqns la boucle
		{
			line = ft_linedup(stock, n);
			ft_bzero(stock, n + 1); 
			free(buff);
			return (line);
		}
	}
	// r = 0 on est sorti de la boucle 
	line = ft_strdup(stock);
	free(stock);
	free(buff);
	return (line);
}