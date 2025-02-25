/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:11:49 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/25 10:43:00 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	sign;

	while (*str == ' ' || (*str >= 7 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nb = 0;
	while (*str && (*str >= '0' && *str <= '9'))
		nb = (nb * 10) + (*str++ - 48);
	return (sign * nb);
}

static size_t	count_word(const char *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			len++;
		i++;
	}
	return (len);
}

void	freedom(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	*word_allocat(const char **s, char c)
{
	int		len;
	char	*res;
    int     i;
    int     j;
    
    j = 0;
	while ((*s)[j] && (*s)[j] == c)
		j++; 
    *s = ((*s) + j);
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    i = 0;
    while(i < len)
    {
        res[i] = (*s)[i];
        i++;   
    }
    res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**big;
	size_t	big_len;

	if (!s)
		return (NULL);
	big_len = count_word(s, c);
	big = (char **)malloc(sizeof(char *) * (big_len + 1));
	if (!big)
		return (NULL);
	i = 0;
	while (i < big_len)
	{
		big[i++] = word_allocat(&s, c);
		if (!big[i - 1])
		{
			freedom(big);
			big = NULL;
			return (NULL);
		}
	}
	big[i] = NULL;
	return (big);
}