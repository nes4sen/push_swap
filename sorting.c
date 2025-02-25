/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:20:29 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/25 16:05:24 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void    turk(int *top_a, int *top_b, int *stack_a, int *stack_b, int ac)
{
        cost holder;
        while (*top_b >= 0)
        {
            holder = best_move(*top_a, *top_b, stack_a, stack_b);
            into_the_top(holder, stack_a, stack_b, *top_a, *top_b, ac);
            // display_stacks(*top_a, stack_a, *top_b, stack_b);
            push(top_a, top_b, stack_a, stack_b,ac, "pa\n");
            // display_stacks(*top_a, stack_a, *top_b, stack_b);

        }
        yassin(*top_a, stack_a, ac);
}
void sorting(int *top_a, int *top_b, int *stack_a, int *stack_b, int ac)
{
    int *arr;
    int pvt;
    
    if (ac == 3)
    {
        trio(stack_a,ac);
        return;
    }
    arr = pseudo_sort(stack_a, ac);
    pvt = arr[(ac / 2)];
    while(*top_a > ac / 2)
    {
        if(stack_a[*top_a] < pvt)
             push(top_b, top_a, stack_b, stack_a, ac, "pb\n");
        rotate(*top_a, stack_a, ac, "ra\n");    
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
}
