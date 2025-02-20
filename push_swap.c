/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:30:48 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/20 16:49:54 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"



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

void trio(int *stack, int size)
{
    if ((stack[0] > stack[1]) && (stack[0] > stack[2]) && (stack[2] > stack[1]))
        swap(2, stack,size, "sa\n");
    else if ((stack[2] > stack[1]) && (stack[2] > stack[0]))
    {
        if (stack[1] > stack[0])
        {
            swap(2, stack,size, "sa\n");
            rev_rotate(2, stack,size ,"rra\n");
        }
        else
            rotate(2, stack,size, "ra\n");
    }
    else if ((stack[1] > stack[0]) && (stack[1] > stack[2]))
    {
        if (stack[0] > stack[2])
        {
            swap(2, stack,size, "sa\n");
            rotate(2, stack,size, "ra\n");
        }
        else
            rev_rotate(2, stack,size, "rra\n");
    }
}

int closest_max(int value, int *stack, int top)
{
    int *arr;
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
void sort(int *top_a, int *top_b, int *stack_a, int *stack_b, int ac)
{
    int i = 0;
    int *arr;
    int div;
    int count = 0;
    int distance;

    div = 8;
    arr = pseudo_sort(stack_a, ac);
    while (*top_a >= 0)
    {
        distance = closest_target(i, stack_a, *top_a, ac, div);
       if (distance > 0)
        {
            while (distance > 0)
            {
                rotate(*top_a, stack_a, ac, "ra\n");
                distance--;
            }
        }
        else
        {
            distance = -distance;
            while (distance > 0)
            {
                rev_rotate(*top_a, stack_a, ac, "rra\n");
                distance--;
            }
        }
         
        push(top_b, top_a, stack_b, stack_a,ac, "pb\n");
        count++;
        if (count == ac / div + 1)
        {
            i++;
            count = 0;
        }
       
    }
//   display_stacks(*top_a, stack_a, *top_b, stack_b);
    // trio(stack_a, ac);
    // printf("i = %d   count = %d   %d \n", i, count, chunky(stack_a[*top_a], arr, ac, div));

    i = 0;
    int flag = 0;
    while (*top_b >= 0)
    {
        int moves;
        
        moves = closest_max(biggest_num(*top_b, stack_b), stack_b, *top_b);
        if(moves > 0)
        {
            while(moves > 0)
            {
                rotate(*top_b, stack_b,ac,"rb\n");
            moves--;
            }
        }else
        {
            moves = -moves;
            while(moves > 0)
            {
                rev_rotate(*top_b, stack_b,ac, "rrb\n");
                moves--;
            }   
        }
        if (moves == 0)
            push(top_a, top_b, stack_a, stack_b,ac, "pa\n");
        // display_stacks(*top_a, stack_a, *top_b, stack_b);
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
            fill_stack(&top_a, atoi(av[max]), stack_a, ac);
            i++;
            max--;
        }

    //   display_stacks(top_a, stack_a, top_b, stack_b);

        sort(&top_a, &top_b, stack_a, stack_b, ac - 1);

        // display_stacks(top_a, stack_a, top_b, stack_b);

        free(stack_a);
        free(stack_b);
    }