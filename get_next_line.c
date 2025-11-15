/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azirari <azirari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:50:32 by azirari           #+#    #+#             */
/*   Updated: 2025/11/15 20:39:00 by azirari          ###   ########.fr       */
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
		buff = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		bytes_r = read(fd, buff, BUFFER_SIZE);
		if (bytes_r < 1)
			return (free(buff), str);
		buff[bytes_r] = '\0';
		i = ft_strchr(buff, '\n');
		if (i > -1)
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

	if (fd < 0)
		return (NULL);
	str = read_fd(fd, str);
	if (!str || !*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	to_ret = malloc(i + 2);
	if (!to_ret)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		to_ret[i] = str[i];
	if (str[i] == '\n')
		to_ret[i++] = '\n';
	to_ret[i] = '\0';
	str = clean_up(str);
	return (to_ret);
}
