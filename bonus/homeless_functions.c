/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homeless_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:06:42 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/16 03:02:57 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaping(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	morgan_freeman(t_stack *s)
{
	free(s->stack_a);
	free(s->stack_b);
}

size_t	count_word(const char *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c && (!str[i + 1] || str[i + 1] == c))
			len++;
		i++;
	}
	return (len);
}

int	count_args(char **av, int ac)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	while (i < ac)
	{
		count += (int )count_word(av[i], ' ');
		i++;
	}
	return (count);
}

void	rr_rrr(t_stack s, int size, char *op)
{
	if (ft_strcmp(op, "rr") == 0)
	{
		rotate(s.top_a, s.stack_a, size, "");
		rotate(s.top_b, s.stack_b, size, "");
		write(1, "rr\n", 3);
	}
	else
	{
		rev_rotate(s.top_a, s.stack_a, size, "");
		rev_rotate(s.top_b, s.stack_b, size, "");
		write(1, "rrr\n", 4);
	}
}
