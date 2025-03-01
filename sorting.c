/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:20:29 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/28 17:20:19 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *pseudo_sort(int *array, int sizee)
{
	int *arr;
	int i;
	int j;
    
	arr = malloc(sizee * sizeof(int));
    if (!arr)
        return NULL;
    ft_memcpy(arr, array, sizee * sizeof(int));
    i = 0;
    while(i < sizee)
    {
        j = i + 1;
        while(j < sizee)
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
void yassin(int top_a, int *stack_a, int size)
{
    int small_num;
    int to_top;
    

    small_num = smallest_num(top_a , stack_a);
    to_top = count_to_top(small_num, stack_a, top_a);
        if(to_top > 0)
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
void    turk(int *top_a, int *top_b, int *stack_a, int *stack_b, int ac)
{
        cost holder;
        while (*top_b >= 0)
        {
            holder = best_move(*top_a, *top_b, stack_a, stack_b);
            into_the_top(holder, stack_a, stack_b, *top_a, *top_b, ac);
            push(top_a, top_b, stack_a, stack_b,ac, "pa\n");
        }
        yassin(*top_a, stack_a, ac);
}
void sorting(int *top_a, int *top_b, int *stack_a, int *stack_b, int ac)
{
    int *arr;
    
    int i = *top_a;
    arr = pseudo_sort(stack_a, ac);
    while((i > ac / 2) && ac > 3)
    {
        if(stack_a[*top_a] <= arr[(ac / 2) - 1])
            push(top_b, top_a, stack_b, stack_a, ac, "pb\n");
        else
        {
            rotate(*top_a, stack_a, ac, "ra\n");
            i++;
        }
        i--;
    }
    while(*top_a > 2)
    {
        if(stack_a[*top_a] >= arr[ac - 3])
              rotate(*top_a, stack_a, ac, "ra\n");
        else
          push(top_b, top_a, stack_b, stack_a, ac, "pb\n");
    }
    trio(stack_a, ac);
    turk(top_a, top_b, stack_a, stack_b, ac);
    free(arr);
}
