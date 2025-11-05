/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azirari <azirari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:39:50 by azirari           #+#    #+#             */
/*   Updated: 2025/11/04 21:48:53 by azirari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_bzero(char *s, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif