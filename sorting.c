/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:20:29 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/02 12:24:15 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*pseudo_sort(int *array, int size)
{
	int *arr;
	int i;
	int j;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return NULL;
	ft_memcpy(arr, array, size * sizeof(int));
	i = 0;
	while(i < size)
	{
		j = i + 1;
		while(j < size)
		{
			if(arr[i] > arr[j])
				swaping(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	return arr;
}

void trio(int *stack, int size)
{
	if (is_sorted(size, stack))
		return; 
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

void back_to_top(int top_a, int *stack_a, int size)
{
	int small_num;
	int to_top;

	small_num = smallest_num(top_a , stack_a);
	to_top = count_to_top(small_num, stack_a, top_a);
	if (to_top > 0)
	{
		while(stack_a[top_a] != small_num )
		{
			rotate(top_a, stack_a, size, "ra\n");
			to_top--;
		}  
	}
	else
	{
		while(stack_a[top_a] != small_num )
		{
			rev_rotate(top_a, stack_a, size, "rra\n");
			to_top++;
		}  
	}
}

void    turk(int *top_a, int *top_b, int *stack_a, int *stack_b, int size)
{
		cost holder;
		while (*top_b >= 0)
		{
			holder = best_move(*top_a, *top_b, stack_a, stack_b);
			into_the_top(holder, stack_a, stack_b, *top_a, *top_b, size);
			push(top_a, top_b, stack_a, stack_b, size, "pa\n");
		}
		back_to_top(*top_a, stack_a, size);
}

void sorting(int *top_a, int *top_b, int *stack_a, int *stack_b, int size)
{
	int *arr;	
	int i;

	i = *top_a;
	arr = pseudo_sort(stack_a, size);
	while ((i > size / 2) && size > 3)
	{
		if (stack_a[*top_a] <= arr[(size / 2) - 1])
			push(top_b, top_a, stack_b, stack_a, size, "pb\n");
		else
		{
			rotate(*top_a, stack_a, size, "ra\n");
			i++;
		}
		i--;
	}
	while (*top_a > 2)
	{
		if(stack_a[*top_a] >= arr[size - 3])
			rotate(*top_a, stack_a, size, "ra\n");
		else
			push(top_b, top_a, stack_b, stack_a, size, "pb\n");
	}
	trio(stack_a, size);
	turk(top_a, top_b, stack_a, stack_b, size);
	free(arr);
}
