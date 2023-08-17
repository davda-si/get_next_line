/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:16:46 by davda-si          #+#    #+#             */
/*   Updated: 2023/08/17 17:13:51 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_line_it(char *buff);
char	*ft_read_extract(int fd, char *buff);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		time_to_free(char *buff);

#endif
#endif