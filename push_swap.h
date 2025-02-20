/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:59:26 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/20 10:45:58 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//operations
void push(int *top_in, int *top_out, int *stack_in, int *stack_out,int size, char *op);
void swap(int top, int *stack,int size, char *op);
void rotate(int top, int *stack,int size, char *op);
void rev_rotate(int top, int *stack,int size, char *op);

//stack utils 
void fill_stack(int *top, int value, int *stack, int ac);
int is_sorted(int top, int *stack);
int is_all_digit(char *str);
int ft_strcmp(char *s1, char *s2);
int error_check(int ac, char **av);
int ft_strlen(char *str);


//sort utils
void trio(int *stack, int size);
int biggest_num(int top, int *stack);
int closest_target(int index, int *stack, int top, int ac, int div);
int *pseudo_sort(int *array, int size);
int is_there(int start, int end,int *arr, int value);
int chunky(int value, int *stack, int size, int div);


#endif
