/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azirari <azirari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:50:32 by azirari           #+#    #+#             */
/*   Updated: 2025/11/06 14:46:42 by azirari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_fd(int fd, char *str)
{
	char	*buff;
	int		i;
	ssize_t	bytes_r;
	int		found_newline;

	found_newline = 0;
	while (!found_newline)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		bytes_r = read(fd, buff, BUFFER_SIZE);
		if (bytes_r < 1)
		{
			free(buff);
			return (str);
		}
		buff[bytes_r] = '\0';
		i = 0;
		while (i < bytes_r && buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
			found_newline = 1;
		if (!str)
			str = ft_strdup(buff);
		else
			str = ft_strjoin(str, buff);
		free(buff);
	}
	return (str);
}

char	*clean_up(char *str)
{
	char	*temp;
	char	*ret;

	ret = NULL;
	temp = str;
	while (*temp && *temp != '\n')
		temp++;
	if (*temp == '\n' && ft_strlen(temp) > 1)
		ret = ft_strdup(++temp);
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*to_ret;
	static char	*str;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = read_fd(fd, str);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	to_ret = malloc(i + 1);
	if (!to_ret)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		to_ret[i] = str[i];
		i++;
	}
	to_ret[i] = '\0';
	str = clean_up(str);
	return (to_ret);
}
