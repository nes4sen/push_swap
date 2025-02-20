/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:56:17 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/20 16:37:37 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

void fill_stack(int *top, int value, int *stack, int ac)
{

    if (*top == ac - 1)
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