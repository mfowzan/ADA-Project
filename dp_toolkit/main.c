// main.c
#include <stdio.h>
#include "dptoolkit.h"

int main()
{
    // Test Fibonacci
    Fibonacci *fib = create_fibonacci(10);
    DPProblem *fib_problem = create_dp_problem(fib, (int (*)(void *))fibonacci_solve);
    printf("Fibonacci of 10: %d\n", dp_solve(fib_problem));
    destroy_dp_problem(fib_problem);
    destroy_fibonacci(fib);

    // Test Knapsack
    int weights[] = {1, 3, 4, 5};
    int values[] = {1, 4, 5, 7};
    int capacity = 7;
    Knapsack *knapsack = create_knapsack(weights, values, 4, capacity);
    DPProblem *knapsack_problem = create_dp_problem(knapsack, (int (*)(void *))knapsack_solve);
    printf("Knapsack maximum value: %d\n", dp_solve(knapsack_problem));
    destroy_dp_problem(knapsack_problem);
    destroy_knapsack(knapsack);

    return 0;
}
