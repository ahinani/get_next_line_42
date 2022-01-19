/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:36:02 by ahinani           #+#    #+#             */
/*   Updated: 2022/01/10 14:54:13 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buff)
{
	char	*dest;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	dest = (char *)malloc(ft_strlen(str) + ft_strlen(buff) + 1);
	if (!dest)
		return (NULL);
	if (str)
		while (str[++i] != '\0')
			dest[i] = str[i];
	while (buff[++j] != '\0')
		dest[i + j] = buff[j];
	dest[i + j] = '\0';
	free(str);
	return (dest);
}

char	*ft_strchr(char *str, int c)
{
	int		a;
	char	*b;

	a = 0;
	b = str;
	while (b[a])
	{
		if (b[a] == (char)c)
			return (&b[a]);
		a++;
	}
	if (b[a] == (char)c)
		return (&b[a]);
	return (0);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = (char *)malloc(sizeof(char) * i + 2);
	else
		line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	if (str[i] != '\n')
		line[i] = '\0';
	else
	{
		line[i] = '\n';
		line[++i] = '\0';
	}
	return (line);
}

char	*get_rest(char *str)
{
	int		i;
	char	*rest;
	int		j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	i++;
	while (str[i] != '\0')
		rest[j++] = str[i++];
	rest[j] = str[i++];
	free(str);
	return (rest);
}
