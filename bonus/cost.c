/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:57:05 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/04 10:45:29 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target(int nb, int top, int *stack)
{
	int	sub;
	int	temp;
	int	hold;

	hold = INT_MAX;
	temp = INT_MAX;
	while (top >= 0)
	{
		sub = stack[top] - (nb);
		if (temp > sub && sub >= 0)
		{
			temp = sub;
			hold = stack[top];
		}
		top--;
	}
	return (hold);
}

static int	absolute(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

t_cost	get_cost(int target_a, int value_b, t_stack s)
{
	t_cost	moves;

	moves.cost_a = count_to_top(target_a, s.stack_a, s.top_a);
	moves.cost_b = count_to_top(value_b, s.stack_b, s.top_b);
	moves.cost_total = absolute(moves.cost_a) + absolute(moves.cost_b);
	return (moves);
}

static void	itt_rotate(t_cost moves, t_stack s, int ac)
{
	while (moves.cost_a > 0 && moves.cost_b > 0)
	{
		rr_rrr(s, ac, "rr");
		moves.cost_a--;
		moves.cost_b--;
	}
	while (moves.cost_a > 0)
	{
		rotate(s.top_a, s.stack_a, ac, "ra\n");
		moves.cost_a--;
	}
	while (moves.cost_b > 0)
	{
		rotate(s.top_b, s.stack_b, ac, "rb\n");
		moves.cost_b--;
	}
}

void	into_the_top(t_cost moves, t_stack s, int ac)
{
	itt_rotate(moves, s, ac);
	while (moves.cost_a < 0 && moves.cost_b < 0)
	{
		rr_rrr(s, ac, "rrr");
		moves.cost_a++;
		moves.cost_b++;
	}
	while (moves.cost_a < 0)
	{
		rev_rotate(s.top_a, s.stack_a, ac, "rra\n");
		moves.cost_a++;
	}
	while (moves.cost_b < 0)
	{
		rev_rotate(s.top_b, s.stack_b, ac, "rrb\n");
		moves.cost_b++;
	}
}
