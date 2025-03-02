/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homeless_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:06:42 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/02 12:02:49 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaping(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
void	morgan_freeman(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
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
