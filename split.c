/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:11:49 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/28 17:15:52 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




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
	*s += len;
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
			return (NULL);
		}
	}
	big[i] = NULL;
	return (big);
}
void free_split(char **av)
{
    int i;

    i = 0;
    while (av[i])
        free(av[i++]);
    free(av);
}