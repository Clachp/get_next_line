/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:32:38 by cchapon           #+#    #+#             */
/*   Updated: 2022/06/11 18:53:01 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Fonction pour recuperer les elements apres le '\n' dans buff
void	get_one_line(char *line, char *buff)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	j = 0;
	while (buff[j])
	{
		buff[j++] = line[i++];
	}
	line[i] = '\0';
	buff[j] = '\0';
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		buff[BUFFER_SIZE + 1];
	int				r;

	r = BUFFER_SIZE;
	line = NULL;
	line = ft_strjoin(line, buff); 
	while (to_end(line) == 0 && r == BUFFER_SIZE) 
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
			return (NULL);
		buff[r] = '\0';
		if (r == 0 && line[0] == '\0')
			return (NULL);
		line = ft_strjoin(line, buff);
	}
	get_one_line(line, buff);
	return (line);
}
