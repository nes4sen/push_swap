#include "push_swap.h"

// Define the struct using typedef
// typedef struct {
//     int a;
//     int b;
// } cost;

// int main() {
//     // Create a variable of type 'cost' and initialize it
//     cost var1 = {10, 20};

//     // Create another variable of type 'cost' and assign var1 to it
//     cost var2 = var1;

//     // Print the values of var1 and var2
//     printf("var1: a = %d, b = %d\n", var1.a, var1.b);
//     printf("var2: a = %d, b = %d\n", var2.a, var2.b);

//     // Modify var1 and see if var2 is affected
//     var1.a = 30;
//     var1.b = 40;

//     // Print the values again
//     printf("After modifying var1:\n");
//     printf("var1: a = %d, b = %d\n", var1.a, var1.b);
//     printf("var2: a = %d, b = %d\n", var2.a, var2.b);

//     return 0;
// }
int main()
{
    int arr1[] = {4, -2};
    int top1 = 1;
    int arr2[] = {2, 5, -3, 7, -1 ,0, 9};
    int top2 = 6;
    cost move;
    move =  best_move(top1, top2, arr1, arr2, 6);

printf("44 nb + %d ||   cost.a = %d || cost.b = %d \n",arr2[top2], move.cost_a, move.cost_b);

}