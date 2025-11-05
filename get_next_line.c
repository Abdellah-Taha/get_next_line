/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azirari <azirari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:50:32 by azirari           #+#    #+#             */
/*   Updated: 2025/11/05 20:47:54 by azirari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_next_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i])
		i++;
	dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*to_return(char *str)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc(has_next_line(str) + 1);
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\n';
	s[++i] = '\0';
	return (s);
}

char	*clean_up(char *str)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	while (str[i] != '\n')
		i++;
	len = ft_strlen(str);
	s = malloc(len - i + 1);
	if (!s)
		return (NULL);
	len = 0;
	i++;
	while (str[i])
		s[len++] = str[i++];
	s[len] = 0;
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*s;
	static char	*str;
	ssize_t		bytes_r;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!str)
	{
		bytes_r = read(fd, buff, BUFFER_SIZE);
		if (bytes_r <= 0)
			return (NULL);
		buff[bytes_r] = 0;
		str = ft_strdup(buff);
		free(buff);
	}
	if (has_next_line(str))
	{
		s = to_return(str);
		str = clean_up(str);
	}
	return (s);
}
