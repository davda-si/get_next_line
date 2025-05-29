/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:24:34 by davda-si          #+#    #+#             */
/*   Updated: 2023/08/24 16:03:12 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0))
	{
		while (buff[i])
			buff[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (buff[0] || read(fd, buff, BUFFER_SIZE))
	{
		line = ft_strjoin(line, buff);
		if (time_to_free(buff))
			break ;
	}
	return (line);
}

/* int main()
{
	int 	fd;
	char	*line;
	
	fd = open("teste.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (0);
} */
