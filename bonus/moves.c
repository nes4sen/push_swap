/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:01:52 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/04 10:14:32 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *s, int size, char *op)
{
	if (s->top_b < 0 || s->top_a >= size - 1)
		return ;
	(s->top_a)++;
	s->stack_a[s->top_a] = s->stack_b[s->top_b];
	(s->top_b)--;
	write(1, op, ft_strlen(op));
}

void	push_b(t_stack *s, int size, char *op)
{
	if (s->top_a < 0 || s->top_b >= size - 1)
		return ;
	(s->top_b)++;
	s->stack_b[s->top_b] = s->stack_a[s->top_a];
	(s->top_a)--;
	write(1, op, ft_strlen(op));
}

void	swap(int top, int *stack, int size, char *op)
{
	int	temp;

	if (top < 1 || top >= size)
		return ;
	temp = stack[top];
	stack[top] = stack[top - 1];
	stack[top - 1] = temp;
	write(1, op, ft_strlen(op));
}

void	rotate(int top, int *stack, int size, char *op)
{
	int	temp;
	int	i;

	if (top < 1 || top >= size)
		return ;
	temp = stack[top];
	i = top;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
	write(1, op, ft_strlen(op));
}

void	rev_rotate(int top, int *stack, int size, char *op)
{
	int	temp;
	int	i;

	if (top >= size || top < 1)
		return ;
	temp = stack[0];
	i = 0;
	while (i < top)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[top] = temp;
	write(1, op, ft_strlen(op));
}
