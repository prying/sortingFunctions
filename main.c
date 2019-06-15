/**************************************
 * Most of the common sorting 
 * algorithms as functions
 * Flynn Harrison
 * 14/05/2019
 *************************************/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define FUNC_DEF(func) { func, #func }
#define NUM_FUNC    1
#define SEED        10
#define RNG         50 // rng size
#define ARRAY_SIZE  10
// Prototypes 
// Sorting functions
void insertion_sort(int *A, size_t n);
// Helper functions
void test_sort(void (*f)(int*,size_t), size_t size);
void test_array(int *A, size_t n);
void swap_int(int *a, int *b);
void print_array(int *A, size_t n);


int main(int argc, char **argv)
{
    time_t t;
    srand((unsigned) time(&t));

    printf("insertion_sort\n");
    test_sort(insertion_sort, ARRAY_SIZE);

    return 0;
}

/* insertion sort algorithm, sorts array A of size n */
void insertion_sort(int *A, size_t n)
{
    if(n <= 1)
        return;
    // Starting point for each number to check
    for(int i = 1; i < n-1; i++)
    {
        for(int j = i; j >= 0; j--)
        {
            if(A[j] > A[j+1])
                swap_int(&A[j], &A[j+1]);
        }
    }
}

/* Test the sort function f with an array of size n*/
void test_sort(void (*f)(int*, size_t), size_t n)
{
    int A[n];
    // Fill array 
    test_array(A, n);
    printf("Intial array: ");
    print_array(A, n);

    // Sort array with function f
    f(A, n);

    printf("Sorted array: ");
    print_array(A, n);
}

/* Creates a test array A of size n*/
void test_array(int *A, size_t n)
{
    for(int i = 0; i<n; i++)
    {
        A[i] = rand() % RNG;
    }
}

/* Prints the array A of size n */
void print_array(int *A, size_t n)
{
    putchar('[');
    for(int i = 0; i<n; i++)
    {
        printf("%d", A[i]);
        // Check if not the last element
        if (i < n-1)
            printf(", ");

    }
    // New line
    puts("]");
}

/* Swaps two ints */
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

