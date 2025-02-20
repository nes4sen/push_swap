/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:17:26 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/20 16:34:46 by nosahimi         ###   ########.fr       */
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
int is_there(int start, int end,int *arr, int value)
{
    int i = start;
    
    while(i <= end)
    {
        if (value == arr[i])
            return 1;
        i++;
    }
    return 0;
}
int closest_target(int index, int *stack, int top, int ac, int div)
{
    int *arr;
    int up;
    int i;
    int butt;
     
    arr = pseudo_sort(stack, ac);
    up = 0;
    i = top;
    while (i >= top / 2)
    {
        if (chunky(stack[i--], arr, ac, div) <= index)
            break;
        up++;
    }
    i = 0;
    butt = 1;
    while (i <= top / 2)
    {
        if (chunky(stack[i++], arr, ac, div) <= index)
            break;
        butt++;
    }
    if (up > butt)
        return (-butt);
    return up;
}
/*
this function check if the number from stack a is allocated in a chunk in stack b ,
it retrun the rank of the number if is found , if not it return -1 
 */ 

int chunky(int value, int *stack, int size, int div)
{
    int offset = size / div;
    int start = 0;
    int end = (start + offset);
    int count = 0;
    int *arr = pseudo_sort(stack, size);
    
    while (start < size)
    {
    //      printf("%d \n",is_there(start, end, arr, value));
    // printf("[offset = %d start = %d end = %d] \n", offset, start, end);
        if(is_there(start, end, arr, value))
            break;
        start = start + offset + 1;
        end = start + offset;
        if (end >= size)
            end = size - 1;
        count++;
    }
        // printf("Value %d is in chunk %d\n", value, count);

    return (count);
}
// int dark_side(int index,  int *stack,int div, int ac)
// {
//     int mid;
//     int i;
//     int top;
//     int butt;
//     int hold;
//     int *arr;

//     arr = pseudo_sort(stack, ac);
//     mid = ac / 2;
//     i = 0;
//     butt = 0;
//     top= 0;
//     while (i <= mid)
//     {
//         if (chunky(stack[i],arr , ac, div)== index)
//             top++;
//             i++;
//         printf("[%d] ", chunky(stack[i],arr , ac, div) );
//     }
    
//     while (i <= ac)
//     {
//         if (chunky(stack[i],arr , ac, div) == index)
//             butt++;
//             i++;
//     }
//     if (top > butt)
//         return (1);
//     return  (-1);
// }
// int chunky(int value, int *stack, int size, int div)
// {
//     int offset = size / div;
//     int start = 0;
//     int end = offset - 1; 
//     int count = 0;
//     int *arr = pseudo_sort(stack, size);

//     while (start < size)
//     {
//         if (is_there(start, end, arr, value))
//             return count;
        
//         count++;
//         start = end + 1;
//         end = start + offset - 1;
        
//         if (end >= size)
//             end = size - 1; 
//     }
//     return count; 
// }

// int  get_index(int *stack, int *top , int *sorted_arr, int ac)
// {
//     int pvt;

//     pvt = sorted_arr[(ac - 1) / 2];
//     while(top >= 0)
//     {
//         if (stack[*top] < pvt) 
//             push(top_b, top_a, stack_b, stack_a, "pb\n");
    
//     }
// }
// int main()
// {

//     int arr[] =  {-3, -2, -1, 1, 5 , 17 , 0, 2, 8, 3, 15, 9 ,6 , 22 ,4 ,32 , 10, 25, 11};
//     int res = chunky(32, arr,16, 3);
//     // printf("%d \n", res);
//     int i = 0;
//     pseudo_sort(arr, 19);
//     printf("side = %d\n",dark_side(0, arr, 4 ,19));
//     while (i < 16)
//     {
//         printf("%d ", arr[i++]);
//     }
    
        
// }