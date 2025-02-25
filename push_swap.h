/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:59:26 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/25 15:19:16 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

typedef struct s_data
{
    int cost_a;
    int cost_b;
    int cost_total;
}cost;

void    display_stacks(int top_a, int *stack_a, int top_b, int *stack_b);


//operations
void push(int *top_in, int *top_out, int *stack_in, int *stack_out,int size, char *op);
void swap(int top, int *stack,int size, char *op);
void rotate(int top, int *stack,int size, char *op);
void rev_rotate(int top, int *stack,int size, char *op);
void rr_rrr(int top_a, int *stack_a,int top_b, int *stack_b, int size, char *op);

//stack utils 
void    fill_stack(int *top, char **av, int *stack, int ac);
int is_sorted(int top, int *stack);
int is_all_digit(char *str);
int ft_strcmp(char *s1, char *s2);
int error_check(int ac, char **av);
int ft_strlen(char *str);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);


//sort utils
void    sorting(int *top_a, int *top_b, int *stack_a, int *stack_b, int ac);
void    turk(int *top_a, int *top_b, int *stack_a, int *stack_b, int ac);
void    yassin(int top_a, int *stack_a, int size);
void    trio(int *stack, int size);
int     biggest_num(int top, int *stack);
int     *pseudo_sort(int *array, int size);

//cost functions
int count_to_top(int value, int *stack, int top);
int smallest_num(int top, int *stack);
int find_target(int nb, int top, int *stack);
void into_the_top(cost moves, int *stack_a, int *stack_b, int top_a, int top_b, int ac);
cost get_cost(int target_a, int value_b, int *stack_a, int *stack_b, int top_a, int top_b);
cost best_move(int top_a, int top_b, int *stack_a, int *stack_b);


#endif
