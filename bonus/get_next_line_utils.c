/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:21:12 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/01 10:19:24 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*p;
	size_t	first_len;
	size_t	sec_len;
	size_t	i;

	if (!str2)
		return (NULL);
	first_len = ft_strlen(str1);
	sec_len = ft_strlen(str2);
	p = (char *)malloc(first_len + sec_len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < first_len)
		p[i++] = *str1++;
	i = 0;
	while (i < sec_len)
		p[first_len + i++] = *str2++;
	p[first_len + sec_len] = '\0';
	return (p);
}

char	*ft_strdup(char *s)
{
	size_t			i;
	char			*p;
	size_t			len;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	char	*sub;
	int		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	str = (char *)s;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && str[start])
		sub[i++] = str[start++];
	sub[len] = '\0';
	return (sub);
}

int	is_new_line(char *str)
{
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}


