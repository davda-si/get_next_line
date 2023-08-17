/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:24:34 by davda-si          #+#    #+#             */
/*   Updated: 2023/08/17 17:20:23 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			ret;

	i = 0;
	if (fd < 1 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
	{
		while (buff[i])
			buff[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		line = ft_strjoin(line, buff);
		if (time_to_free(buff))
			break ;
	}
	return (line);
}

int	main()
{
	int		fd = 0;
	char	*f;

	fd = open("./teste.txt", O_RDONLY);
	f = get_next_line(fd);
	printf("%s", f);
	close(fd);
}