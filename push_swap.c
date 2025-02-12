/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:30:48 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/12 18:57:21 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define size 500

// Define ANSI color codes for better visualization
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

void display_stacks(int top_a, int *stack_a, int top_b, int *stack_b)
{
    printf("\n");
    printf(YELLOW "┌─────────────┐\t┌─────────────┐\n" RESET);
    printf(YELLOW "│" BLUE " Stack A    " YELLOW "│\t│" BLUE " Stack B    " YELLOW "│\n" RESET);
    printf(YELLOW "├─────────────┤\t├─────────────┤\n" RESET);

    // Determine the maximum height of the two stacks
    int max_height = (top_a > top_b) ? top_a : top_b;

    // Print the stacks side by side
    for (int i = max_height; i >= 0; i--)
    {
        // Print stack A
        printf(YELLOW "│" RESET);
        if (i <= top_a)
            printf(GREEN " %-11d " RESET, stack_a[i]);
        else
            printf("             ");
        printf(YELLOW "│\t" RESET);

        // Print stack B
        printf(YELLOW "│" RESET);
        if (i <= top_b)
            printf(RED " %-11d " RESET, stack_b[i]);
        else
            printf("             ");
        printf(YELLOW "│\n" RESET);
    }

    printf(YELLOW "└─────────────┘\t└─────────────┘\n" RESET);
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
void push(int *top_in, int *top_out, int *stack_in, int *stack_out, char *op)
{
    if (*top_in == size - 1)
    {
        write(1, "stack overflow\n", 16);
        return;
    }
    (*top_in)++;
    stack_in[*top_in] = stack_out[*top_out];
    (*top_out)--;
    write(1, op, ft_strlen(op));
    return;
}

void swap(int top, int *stack, char *op)
{
    int temp;

    if (top == size - 1)
    {
        write(1, "stack overslow\n", 16);
        return;
    }
    if (top == size - 2)
    {
        write(1, op, ft_strlen(op));
        return;
    }
    temp = stack[top];
    stack[top] = stack[top - 1];
    stack[top - 1] = temp;
    write(1, op, ft_strlen(op));
    return;
}

void rotate(int top, int *stack, char *op)
{
    int temp;
    int i;
    if (top == size - 1)
    {
        write(1, "stack overslow\n", 16);
        return;
    }
    if (top == size - 2)
    {
        write(1, op, ft_strlen(op));
        return;
    }
    temp = stack[top];
    i = top;
    while (i > 0)
    {
        stack[i] = stack[i - 1];
        i--;
    }
    stack[0] = temp;
    write(1, op, ft_strlen(op));
    return;
}
void rev_rotate(int top, int *stack, char *op)
{
    int temp;
    int i;
    if (top == size - 1)
    {
        write(1, "stack overslow\n", 16);
        return;
    }
    if (top == size - 2)
    {
        write(1, op, ft_strlen(op));
        return;
    }
    temp = stack[0];
    i = 0;
    while (i < top)
    {
        stack[i] = stack[i + 1];
        i++;
    }
    stack[top] = temp;
    write(1, op, ft_strlen(op));
    return;
}

void fill_stack(int *top, int value, int *stack)
{

    if (*top == size - 1)
        return;
    (*top)++;
    stack[*top] = value;
}

int is_sorted(int top, int *stack)
{
    int i;

    i = 0;
    while (i < top)
    {
        if (stack[i] < stack[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int is_all_digit(char *str)
{
    if (*str == '+' || *str == '-')
        str++;
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return 0;
        str++;
    }
    return 1;
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}

int error_check(int ac, char **av)
{
    int i;
    int j;
    i = 1;

    while (i < ac)
    {
        j = i + 1;
        if (is_all_digit(av[i]) == 0)
            return 0;
        while (j < ac)
        {
            if (ft_strcmp(av[i], av[j]) == 0)
                return 0;
            j++;
        }
        i++;
    }

    return 1;
}
void threesom(int *stack)
{
    if((stack[0] > stack[1]) && (stack[0] > stack[2]) && (stack[2] > stack[1]))
        swap(2, stack, "sa\n");
    else if((stack[2] > stack[1]) &&  (stack[2] > stack[0]))
    {
        if(stack[1] > stack[0])
        {
            swap(2, stack, "sa\n");
            rev_rotate(2,stack, "rra\n");
        }
        else
            rotate(2,stack, "ra\n");
    }
    else if ((stack[1] > stack[0]) && (stack[1] > stack[2]))
    {
        if (stack[0] > stack[2])
        {
            swap(2, stack, "sa\n");
            rotate(2,stack, "ra\n");
        }
        else
            rev_rotate(2,stack, "rra\n");
    }
}
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

    big_num = biggest_num(top, stack);
    temp = big_num;
    while(top >= 0)
    {
        sub = nb - stack[top];
        if(temp < sub)
            temp = nb;
        top--;
    }
    return temp;
}
int which_side(int target, int top, int *stack)
{
    int middle;
    int count ;

    count = 0;
    middle = (top) / 2;
    while(top >= 0 && target != stack[top])
    {
        top--;
        count++;
    }
    return (count);
}
void sort(int *top_a, int *top_b, int *stack_a, int *stack_b)
{
    int target;
    int cost;

    if()
    if (*top_a == 3) 
        push(top_b, top_a, stack_b, stack_a, "pb\n");
    else if(*top_a > 3)
    {
        push(top_b, top_a, stack_b, stack_a, "pb\n");
        push(top_b, top_a, stack_b, stack_a, "pb\n");
    }
    while(!is_sorted(*top_a, stack_a) && *top_a >= 2)
    {
        // push(top_b, top_a, stack_b, stack_a, "pb\n");
        // target = find_target(stack_a[*top_a], *top_b, stack_b);
        //  display_stacks(*top_a, stack_a, *top_b, stack_b);
        // if(which_side(target, *top_b, stack_b) == -1)
        // {
        //     printf("target = %d  nb = %d\n", target, stack_b[*top_b]);
        //    rotate(*top_b,stack_b, "ra\n");
        // }
        if(which_side(stack_a[*top_a], *top_b, stack_b) == 1)
            push(top_b, top_a, stack_b, stack_a, "pb\n");
        else
            rotate(*top_a,stack_a, "ra\n");
  
    

        if (*top_a == 2)
        {
            threesom(stack_a);
            return ;
        }
    }   
 
}

int main(int ac, char *av[])
{
    int top_a;
    int top_b;
    int *stack_a = malloc(sizeof(int) * (ac - 1));
    int *stack_b = malloc(sizeof(int) * (ac - 1));

    if (!stack_a || !stack_b)
    {
        write(1, "Memory allocation failed\n", 22);
        return 1;
    }

    if (ac < 2)
    {
        write(1, "stack a is empty\n", 18);
        return 0;
    }
    if (error_check(ac, av) == 0)
    {
        write(1, "error\n", 7);
        return (0);
    }
    top_a = -1;
    top_b = -1;
    int i;
    int max;
    max = ac - 1;
    i = 0;
    while (i < ac - 1)
    {
        fill_stack(&top_a, atoi(av[max]), stack_a);
        i++;
        max--;
    }

    display_stacks(top_a, stack_a, top_b, stack_b);
    
    sort(&top_a, &top_b, stack_a, stack_b);
    
    display_stacks(top_a, stack_a, top_b, stack_b);


    free(stack_a);
    free(stack_b);
}