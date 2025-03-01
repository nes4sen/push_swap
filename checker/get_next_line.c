/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:21:15 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/28 18:38:40 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*find_line(int fd, char *container, char *buff)
{
	char	*temp;
	ssize_t	r_size;

	r_size = 1;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (r_size > 0)
	{
		r_size = read(fd, buff, BUFFER_SIZE);
		if (r_size == -1)
			return (NULL);
		buff[r_size] = '\0';
		if (r_size == 0)
			break ;
		temp = ft_strjoin(container, buff);
		free(container);
		container = temp;
		if (is_new_line(buff))
			break ;
	}
	return (container);
}

static char	*get_line(char *str)
{
	size_t	len;
	char	*line;

	if (!*str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = ft_substr(str, 0, len);
	return (line);
}

static char	*get_rest(char *str)
{
	size_t	len;
	char	*rest;

	if (!*str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	rest = ft_substr(str, len, ft_strlen(str) - len);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*temp;
	char		*line;
	char		*buff;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	temp = find_line(fd, container, buff);
	if (!temp)
	{
		free(container);
		free(buff);
		container = NULL;
		return (buff = NULL, NULL);
	}
	line = get_line(temp);
	container = get_rest(temp);
	free(temp);
	free(buff);
	temp = NULL;
	buff = NULL;
	return (line);
}
