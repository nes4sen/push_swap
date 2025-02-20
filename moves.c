/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:01:52 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/20 11:08:36 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



#include "push_swap.h"

void push(int *top_in, int *top_out, int *stack_in, int *stack_out, int size, char *op)
{
    // Check if there are elements to push from out stack
    if (*top_out < 0)
    {
        printf("toto 1");
        return;
    }
    
    // Check for overflow
    if (*top_in >= size - 1)
    {
        printf("toto 1. 1");
        
        return;
    }
    
    (*top_in)++;
    stack_in[*top_in] = stack_out[*top_out];
    (*top_out)--;
    write(1, op, ft_strlen(op));
}

void swap(int top, int *stack, int size, char *op)
{
    // Need at least 2 elements to swap
    if (top < 1)
    {
        printf("toto 2");
        
        return;
    }
        
    // Check bounds
    if (top >= size)
    {
        printf("toto 2.1");
        
        return;
    }
    
    int temp = stack[top];
    stack[top] = stack[top - 1];
    stack[top - 1] = temp;
    write(1, op, ft_strlen(op));
}

void rotate(int top, int *stack, int size, char *op)
{
    // Need at least 2 elements to rotate
    if (top < 1)
    {
        printf("toto 3");
        
        return;
    }
        
    // Check bounds
    if (top >= size)
    {
        printf("toto 3");

        return;
    }
    
    int temp = stack[top];
    for (int i = top; i > 0; i--)
        stack[i] = stack[i - 1];
    stack[0] = temp;
    write(1, op, ft_strlen(op));
}

void rev_rotate(int top, int *stack, int size, char *op)
{
    // Need at least 2 elements to reverse rotate
    if (top < 1)
        return;
        
    // Check bounds
    if (top >= size)
        return;
    
    int temp = stack[0];
    for (int i = 0; i < top; i++)
        stack[i] = stack[i + 1];
    stack[top] = temp;
    write(1, op, ft_strlen(op));
}


/*
    target = find_target(stack_a[*top_a], *top_b, stack_b);
    display_stacks(*top_a, stack_a, *top_b, stack_b);

        rank = which_side(target, *top_b, stack_b);
        pull = rank;
        if(rank < (*top_b / 2) - 1)
        {
            printf("rank = %d\n", rank);
            while(pull >= 0)
            {
                rev_rotate(*top_b,stack_b, "rrb\n");
                pull--;
            }
        }
        else
        {
                while(pull >= 0)
            {
            printf("%d\n", rank);

                rev_rotate(*top_b,stack_b, "rrb\n");
                pull--;
            }



*****************


int biggest_num(int top, int *stack)
{
    int temp;

    temp = stack[top];
    while(top >= 0)
    {
        if (stack[top] > temp)
            temp = stack[top];
        top--;
    }
    return temp;
}

int find_target(int nb, int top, int *stack)
{
    int sub;
    int temp;
    int big_num;
    int hold;

    big_num = biggest_num(top, stack);
    hold = big_num;
    temp = big_num;
 
    while(top >= 0)
    {
        sub = nb - stack[top];
        if(temp > sub && sub >= 0)
        {
            temp = sub;
            hold = stack[top];
        }
        top--;
    }
    return hold;
}
int which_side(int target, int top, int *stack)
{
    int middle;
    int count ;

    count = 0;
    middle = (top / 2);
    while(top >= 0 && target != stack[top])
    {
        top--;
        count++;
    }
    return (count);
}
*/