/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:17:51 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/04 10:25:56 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_to_top(int value, int *stack, int top)
{
	int	up;
	int	butt;
	int	i;

	up = 0;
	i = top;
	while (i >= top / 2)
	{
		if (stack[i--] == value)
			break ;
		up++;
	}
	i = 0;
	butt = 1;
	while (i < top / 2)
	{
		if (stack[i++] == value)
			break ;
		butt++;
	}
	if (up > butt)
		return (-butt);
	return (up);
}

t_cost	best_move(t_stack s)
{
	t_cost	holder;
	t_cost	temp;
	int		target_a;
	int		i;

	i = s.top_b;
	holder.cost_a = INT_MAX;
	holder.cost_b = INT_MAX;
	holder.cost_total = INT_MAX;
	while (i >= 0)
	{
		target_a = find_target(s.stack_b[i], s.top_a, s.stack_a);
		temp = get_cost(target_a, s.stack_b[i], s);
		if (holder.cost_total > temp.cost_total)
			holder = temp;
		i--;
	}
	return (holder);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	biggest_num(int top, int *stack)
{
	int	temp;

	temp = stack[top];
	while (top >= 0)
	{
		if (stack[top] > temp)
			temp = stack[top];
		top--;
	}
	return (temp);
}

int	smallest_num(int top, int *stack)
{
	int	temp;

	temp = stack[top];
	while (top >= 0)
	{
		if (stack[top] < temp)
			temp = stack[top];
		top--;
	}
	return (temp);
}
