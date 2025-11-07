/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azirari <azirari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:07:28 by azirari           #+#    #+#             */
/*   Updated: 2025/11/07 14:12:18 by azirari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
			return (free(buff), str);
		buff[bytes_r] = '\0';
		i = ft_strchr(buff, '\n');
		if (i >= 0 && buff[i] == '\n')
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
	static char	*str[1024];
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str[fd] = read_fd(fd, str[fd]);
	if (!str[fd] || !*str[fd])
		return (NULL);
	i = 0;
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	to_ret = malloc(i + 2);
	if (!to_ret)
		return (NULL);
	i = 0;
	while (str[fd][i] && str[fd][i] != '\n')
	{
		to_ret[i] = str[fd][i];
		i++;
	}
	if (str[fd][i] == '\n')
		to_ret[i++] = '\n';
	to_ret[i] = '\0';
	str[fd] = clean_up(str[fd]);
	return (to_ret);
}