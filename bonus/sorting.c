/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:20:29 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/04 10:07:38 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*pseudo_sort(int *array, int size)
{
	int	*arr;
	int	i;
	int	j;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	ft_memcpy(arr, array, size * sizeof(int));
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				swaping(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	return (arr);
}

void	trio(int *stack, int size)
{
	if (is_sorted(size, stack))
		return ;
	if ((stack[0] > stack[1]) && (stack[0] > stack[2]) && (stack[2] > stack[1]))
		swap(2, stack, size, "sa\n");
	else if ((stack[2] > stack[1]) && (stack[2] > stack[0]))
	{
		if (stack[1] > stack[0])
		{
			swap(2, stack, size, "sa\n");
			rev_rotate(2, stack, size, "rra\n");
		}
		else
			rotate(2, stack, size, "ra\n");
	}
	else if ((stack[1] > stack[0]) && (stack[1] > stack[2]))
	{
		if (stack[0] > stack[2])
		{
			swap(2, stack, size, "sa\n");
			rotate(2, stack, size, "ra\n");
		}
		else
			rev_rotate(2, stack, size, "rra\n");
	}
}

void	back_to_top(int top_a, int *stack_a, int size)
{
	int	small_num;
	int	to_top;

	small_num = smallest_num(top_a, stack_a);
	to_top = count_to_top(small_num, stack_a, top_a);
	if (to_top > 0)
	{
		while (stack_a[top_a] != small_num)
		{
			rotate(top_a, stack_a, size, "ra\n");
			to_top--;
		}
	}
	else
	{
		while (stack_a[top_a] != small_num)
		{
			rev_rotate(top_a, stack_a, size, "rra\n");
			to_top++;
		}
	}
}

void	turk(t_stack *s, int size)
{
	t_cost	holder;

	while (s->top_b >= 0)
	{
		holder = best_move(*s);
		into_the_top(holder, *s, size);
		push_a(s, size, "pa\n");
	}
	back_to_top(s->top_a, s->stack_a, size);
}

void	sorting(t_stack *s, int size)
{
	int	*arr;	
	int	i;

	i = s->top_a;
	arr = pseudo_sort(s->stack_a, size);
	while ((i > size / 2) && size > 3)
	{
		if (s->stack_a[s->top_a] <= arr[(size / 2) - 1])
			push_b(s, size, "pb\n");
		else
		{
			rotate(s->top_a, s->stack_a, size, "ra\n");
			i++;
		}
		i--;
	}
	while (s->top_a > 2)
	{
		if (s->stack_a[s->top_a] >= arr[size - 3])
			rotate(s->top_a, s->stack_a, size, "ra\n");
		else
			push_b(s, size, "pb\n");
	}
	(trio(s->stack_a, size), turk(s, size));
	free(arr);
}
