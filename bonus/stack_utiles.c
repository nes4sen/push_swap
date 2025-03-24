/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:56:17 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/16 16:04:40 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (!s1 && !s2)
		return (NULL);
	while (n--)
		*s1++ = *s2++;
	return (dest);
}

long	ft_atoi(const char *str)
{
	long	nb;
	int		sign;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
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
	{
		nb = (nb * 10) + (*str++ - 48);
		if (nb > 2147483649)
			return (LONG_MAX);
	}
	nb = sign * nb;
	if (nb < -2147483648)
		return (LONG_MIN);
	return (nb);
}

static void	int_range(char *str, t_stack *s, char **fill, int *av_cpy)
{
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
	{
		write(2, "Error\n", 6);
		morgan_freeman(s);
		free_split(fill);
		free(av_cpy);
		exit(1);
	}
}

static int	fill_stack_helper(t_stack *s, char **av, int ac, int *av_cpy)
{
	int		count;
	int		i;
	int		j;
	char	**fill;

	i = 1;
	count = 0;
	while (i < ac)
	{
		j = 0;
		fill = ft_split(av[i], ' ');
		if (!fill)
			(free_split(fill), morgan_freeman(s), free(av_cpy), exit(1));
		while (fill[j] != NULL)
		{
			int_range(fill[j], s, fill, av_cpy);
			av_cpy[count++] = ft_atoi(fill[j]);
			j++;
		}
		free_split(fill);
		i++;
	}
	return (count);
}

void	fill_stack(t_stack *s, char **av, int ac, int len)
{
	int		i;
	int		count;
	int		*av_cpy;

	count = 0;
	av_cpy = malloc(sizeof(int) * len);
	if (!av_cpy)
		return ;
	count = fill_stack_helper(s, av, ac, av_cpy);
	i = count - 1;
	while (i >= 0)
		s->stack_a[++(s->top_a)] = av_cpy[i--];
	free(av_cpy);
}
