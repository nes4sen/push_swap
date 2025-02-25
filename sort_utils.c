/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:17:26 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/25 09:09:55 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int *pseudo_sort(int *array, int sizee)
{
    int *arr;
    int i;
    int j;
    int temp;
    arr = malloc(sizee * sizeof(int));
    if (!arr)
        return NULL;
    memcpy(arr, array, sizee * sizeof(int));
    i = 0;
    while(i < sizee)
    {
        j = i + 1;
        while(j < sizee)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
    }
    return arr;
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
