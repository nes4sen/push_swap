/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:17:51 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/28 17:12:20 by nosahimi         ###   ########.fr       */
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
    while (i >= top / 2)
    {
        if (stack[i--] == value)
            break;
        up++;
    }
    i = 0;
    butt = 1;
    while (i < top / 2)
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

int ft_strlen(char *str)
{
    int count;

    count = 0;
    while (str[count])
    {
        count++;
    }
    return (count);
}
int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}
int biggest_num(int top, int *stack)
{
    int temp;

    temp = stack[top];
    while (top >= 0)
    {
        if (stack[top] > temp)
            temp = stack[top];
        top--;
    }
    return temp;
}

int smallest_num(int top, int *stack)
{
    int temp;

    temp = stack[top];
    while (top >= 0)
    {
        if (stack[top] < temp)
            temp = stack[top];
        top--;
    }
    return temp;
}