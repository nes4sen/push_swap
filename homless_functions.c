/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homless_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:17:51 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/25 09:40:48 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_to_top(int value, int *stack, int top)
{
    int up;
    int butt;
    int i;

    up = 0;
    i = top;
    while (i > top / 2)
    {
        if (stack[i--] == value)
            break;
        up++;
    }
    i = 0;
    butt = 1;
    while (i <= top / 2)
    {
        if (stack[i++] == value)
            break;
        butt++;
    }
    if (up > butt)
        return (-butt);
    return up;
}
cost best_move(int top_a, int top_b, int *stack_a, int *stack_b)
{
    cost holder;
    cost temp;
    int target_a;
    int i = top_b;
  
  holder.cost_a = INT_MAX;
  holder.cost_b = INT_MAX;
  holder.cost_total =INT_MAX;
    while (i >= 0)
    {
   
        target_a = find_target(stack_b[i], top_a, stack_a);
         temp = get_cost(target_a, stack_b[i], stack_a, stack_b, top_a, top_b);
        if (holder.cost_total > temp.cost_total)
            holder = temp;
        i--;
    }       
  
    return (holder);
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
