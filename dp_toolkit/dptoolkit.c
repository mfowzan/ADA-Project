// dptoolkit.c
#include <stdio.h>
#include <stdlib.h>
#include "dptoolkit.h"

// Helper function to initialize memoization array for Fibonacci
int *init_fibonacci_memo(int n)
{
    int *memo = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; ++i)
    {
        memo[i] = -1;
    }
    return memo;
}

// Fibonacci functions
Fibonacci *create_fibonacci(int n)
{
    Fibonacci *fib = (Fibonacci *)malloc(sizeof(Fibonacci));
    fib->n = n;
    fib->memo = init_fibonacci_memo(n);
    return fib;
}

void destroy_fibonacci(Fibonacci *fib)
{
    if (fib)
    {
        free(fib->memo);
        free(fib);
    }
}

int fibonacci_solve_helper(Fibonacci *fib, int n)
{
    if (fib->memo[n] != -1)
    {
        return fib->memo[n];
    }
    if (n <= 1)
    {
        fib->memo[n] = n;
    }
    else
    {
        fib->memo[n] = fibonacci_solve_helper(fib, n - 1) + fibonacci_solve_helper(fib, n - 2);
    }
    return fib->memo[n];
}

int fibonacci_solve(Fibonacci *fib)
{
    return fibonacci_solve_helper(fib, fib->n);
}

// Helper function to initialize memoization array for Knapsack
int **init_knapsack_memo(int n, int capacity)
{
    int **memo = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; ++i)
    {
        memo[i] = (int *)malloc((capacity + 1) * sizeof(int));
        for (int j = 0; j <= capacity; ++j)
        {
            memo[i][j] = -1;
        }
    }
    return memo;
}

// Knapsack functions
Knapsack *create_knapsack(int *weights, int *values, int n, int capacity)
{
    Knapsack *knapsack = (Knapsack *)malloc(sizeof(Knapsack));
    knapsack->weights = weights;
    knapsack->values = values;
    knapsack->n = n;
    knapsack->capacity = capacity;
    knapsack->memo = init_knapsack_memo(n, capacity);
    return knapsack;
}

void destroy_knapsack(Knapsack *knapsack)
{
    if (knapsack)
    {
        for (int i = 0; i <= knapsack->n; ++i)
        {
            free(knapsack->memo[i]);
        }
        free(knapsack->memo);
        free(knapsack);
    }
}

int knapsack_solve_helper(Knapsack *knapsack, int i, int w)
{
    if (i < 0 || w == 0)
    {
        return 0;
    }
    if (knapsack->memo[i][w] != -1)
    {
        return knapsack->memo[i][w];
    }
    if (knapsack->weights[i] > w)
    {
        knapsack->memo[i][w] = knapsack_solve_helper(knapsack, i - 1, w);
    }
    else
    {
        int include = knapsack->values[i] + knapsack_solve_helper(knapsack, i - 1, w - knapsack->weights[i]);
        int exclude = knapsack_solve_helper(knapsack, i - 1, w);
        knapsack->memo[i][w] = (include > exclude) ? include : exclude;
    }
    return knapsack->memo[i][w];
}

int knapsack_solve(Knapsack *knapsack)
{
    return knapsack_solve_helper(knapsack, knapsack->n - 1, knapsack->capacity);
}

// Solver functions
DPProblem *create_dp_problem(void *instance, int (*solve)(void *instance))
{
    DPProblem *problem = (DPProblem *)malloc(sizeof(DPProblem));
    problem->instance = instance;
    problem->solve = solve;
    return problem;
}

void destroy_dp_problem(DPProblem *problem)
{
    if (problem)
    {
        free(problem);
    }
}

int dp_solve(DPProblem *problem)
{
    return problem->solve(problem->instance);
}
