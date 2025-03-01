/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:40:20 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/28 18:40:41 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void push(int *top_in, int *top_out, int *stack_in, int *stack_out, int size, char *op)
{
    if (*top_out < 0 || *top_in >= size - 1)
        return;
    (*top_in)++;
    stack_in[*top_in] = stack_out[*top_out];
    (*top_out)--;
    write(1, op, ft_strlen(op));
}

void swap(int top, int *stack, int size, char *op)
{
    int temp;
    
    if (top < 1 || top >= size)   
        return;
    temp = stack[top];
    stack[top] = stack[top - 1];
    stack[top - 1] = temp;
    write(1, op, ft_strlen(op));
}

void rotate(int top, int *stack, int size, char *op)
{
    int temp;
    int i;
    
    if (top < 1 || top >= size)
        return;
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

void rev_rotate(int top, int *stack, int size, char *op)
{
    int temp;
    int i;

   
    if (top >= size || top < 1)
        return;
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

void rr_rrr(int top_a, int *stack_a,int top_b, int *stack_b, int size, char *op)
{
    if (ft_strcmp(op, "rr") == 0)
    {
        rotate(top_a, stack_a, size, "");
        rotate(top_b, stack_b, size, "");
        write(1, "rr\n",3);
    }
    else
    {
        rev_rotate(top_a, stack_a, size, "");
        rev_rotate(top_b, stack_b, size, "");
        write(1, "rrr\n",4);
    }
}