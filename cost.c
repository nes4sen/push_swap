/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:57:05 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/28 16:55:07 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int find_target(int nb, int top, int *stack)
{
    int sub;
    int temp;
    int bigg_num;
    int hold;

    bigg_num = smallest_num(top, stack);
    hold = INT_MAX;
    temp = INT_MAX;
    while (top >= 0)
    {
        sub =  stack[top] - (nb);
        if (temp > sub && sub >= 0)
        {
            temp = sub;
            hold = stack[top];
        }
        top--;
    }
    return hold;
}
static int absolute(int nb)
{
    if (nb < 0)
        return -nb;
    return nb;
}
cost get_cost(int target_a, int value_b, int *stack_a, int *stack_b, int top_a, int top_b)
{
    cost moves;

    moves.cost_a = count_to_top(target_a, stack_a, top_a);
    moves.cost_b = count_to_top(value_b, stack_b, top_b);
    moves.cost_total = absolute(moves.cost_a) + absolute(moves.cost_b);
    return moves;
}
static void itt_rotate(cost moves, int *stack_a, int *stack_b, int top_a, int top_b, int ac)
{
     while (moves.cost_a > 0 && moves.cost_b > 0)
        {
     
            rr_rrr(top_a, stack_a,top_b, stack_b, ac, "rr");
            moves.cost_a--;
            moves.cost_b--;
        }
        while (moves.cost_a > 0)
        {
            rotate(top_a, stack_a, ac, "ra\n");
            moves.cost_a--;
        }
        while (moves.cost_b > 0)
        {
            rotate(top_b, stack_b, ac, "rb\n");
            moves.cost_b--;
        }
}
void into_the_top(cost moves, int *stack_a, int *stack_b, int top_a, int top_b, int ac)
{
	
        itt_rotate(moves, stack_a, stack_b, top_a, top_b, ac);
        while (moves.cost_a < 0 && moves.cost_b < 0)
        {
			rr_rrr(top_a, stack_a,top_b, stack_b, ac, "rrr");
			moves.cost_a++;
			moves.cost_b++;
        }
        while (moves.cost_a < 0)
        {
            rev_rotate(top_a, stack_a, ac, "rra\n");
            moves.cost_a++;
        }
        while (moves.cost_b < 0)
        {
            rev_rotate(top_b, stack_b, ac, "rrb\n");
            moves.cost_b++;
        }
}

