#ifndef DPTOOLKIT_H
#define DPTOOLKIT_H

// Structure representing a dynamic programming problem
typedef struct DPProblem
{
    void *instance;             // Instance of the problem (e.g., Fibonacci, Knapsack)
    int (*solve)(void *instance);  // Function pointer to the solve function
} DPProblem;

// Fibonacci structure and functions

// Structure representing a Fibonacci problem
typedef struct Fibonacci
{
    int n;       // The nth Fibonacci number to compute
    int *memo;   // Memoization array for storing intermediate results
} Fibonacci;

// Creates a new Fibonacci instance
Fibonacci *create_fibonacci(int n);

// Destroys a Fibonacci instance and frees allocated memory
void destroy_fibonacci(Fibonacci *fib);

// Solves the Fibonacci problem using memoization
int fibonacci_solve(Fibonacci *fib);

// Knapsack structure and functions

// Structure representing a Knapsack problem
typedef struct Knapsack
{
    int *weights;    // Array of item weights
    int *values;     // Array of item values
    int n;           // Number of items
    int capacity;    // Capacity of the knapsack
    int **memo;      // Memoization array for storing intermediate results
} Knapsack;

// Creates a new Knapsack instance
Knapsack *create_knapsack(int *weights, int *values, int n, int capacity);

// Destroys a Knapsack instance and frees allocated memory
void destroy_knapsack(Knapsack *knapsack);

// Solves the Knapsack problem using memoization
int knapsack_solve(Knapsack *knapsack);

// Solver functions

// Creates a new dynamic programming problem instance
DPProblem *create_dp_problem(void *instance, int (*solve)(void *instance));

// Destroys a dynamic programming problem instance and frees allocated memory
void destroy_dp_problem(DPProblem *problem);

// Solves a dynamic programming problem
int dp_solve(DPProblem *problem);

#endif // DPTOOLKIT_H
