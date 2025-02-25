/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:30:48 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/25 16:07:56 by nosahimi         ###   ########.fr       */
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
static void morgan_freeman(int *stack_a, int *stack_b)
{
    free(stack_a);
    free(stack_b);
}

int main(int ac, char *av[])
{
    int top_a;
    int top_b;
    int *stack_a ;
    int *stack_b ;

    stack_a = malloc(sizeof(int) * (ac - 1));
    stack_b = malloc(sizeof(int) * (ac - 1));
    if (!stack_a || !stack_b || error_check(ac, av) == 0)
    {
        morgan_freeman(stack_a, stack_b);
        return 0;
    }
    top_a = -1;
    top_b = -1;
    fill_stack(&top_a, av, stack_a, ac);
    display_stacks(top_a, stack_a, top_b, stack_b);
    sorting(&top_a, &top_b, stack_a, stack_b, ac - 1);
    display_stacks(top_a, stack_a, top_b, stack_b);
    morgan_freeman(stack_a, stack_b);
}
