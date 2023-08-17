/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:24:46 by davda-si          #+#    #+#             */
/*   Updated: 2023/08/17 17:20:05 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	if (!s)
		return (0);
	while (s[a] && s[a] != '\n')
		a++;
	if (s[a] == '\n')
		a++;
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && s2[j] != '\n')
	{
		str[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

int	time_to_free(char *buff)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while(buff[i])
	{
		if (check == 0)
		{
			buff[j] = buff[i];
			j++;
		}
		if (buff[i] == '\n')
			check = 1;
		i++;
	}
	return (check);
}

/* int main()
{
	char	*s2 = "gojo\nsatoru";
	int 	tf = time_to_free(s2);
	printf("%d", tf);
} */