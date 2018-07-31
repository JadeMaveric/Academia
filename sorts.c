#include "sorts.h"
#include <stdio.h>

void bubble_sort(int * list, unsigned int size, char verbose)
{
    int i, k; //Iterator
    int limit = size; //Limit for checking, decreases each pass
    enum bool {false, true} sorted = false;

    // Bubble Sort does at most k passes
    for(k=0; k<size; k++)
    {
        // Verbose: Output Array
        if(verbose == 'V')
        {
            int j;
            printf("Pass %d:\n", k+1);
            for(j=0; j<size; j++)
            {
                printf("%d ", list[j]);
            }
            printf("\n");
        }

        for(i=1; i<limit; i++)
        {
            // Check if adjacent elements are not in the correct order
            if( list[i] < list[i-1])
            {
                // Verbose: Print array as it is being modified
                if(verbose == 'V')
                {
                    int j;
                    for(j=0; j<i-1; j++)
                        printf("%d ", list[j]);
                    printf("\033[1;31m%d \033[0m", list[i-1]);
                    printf("\033[1;32m%d \033[0m", list[i]);
                    for(j = i+1; j < size; j++)
                        printf("%d ", list[j]);
                    printf("\n");

                }

                // Switch the elements
                list[i]   = list[i] + list[i-1];
                list[i-1] = list[i] - list[i-1];
                list[i]   = list[i] - list[i-1];

                // Reset the SORTED flag
                sorted = false;
            }
        }
        // Last element is in its correct position. Don't change it
        limit--;

        //Check if Array is sorted
        if(sorted == true)
        {
            if(verbose == 'V')
                printf("Array is sorted!\n");
            return;
        }
        else
        {
            sorted = true;
        }
    }
}

void selection_sort(int * list, unsigned int size, char verbose)
{
    int i, j;
    int large;

    for(i=0; i<size; i++)
    {
        // Verbose: Output Array
        if(verbose == 'V')
        {
            int j;
            printf("Pass %d:\n", i+1);
            for(j=0; j<size; j++)
            {
                printf("%d ", list[j]);
            }
            printf("\n");
        }

        for(j=i+1; j<size; j++)
        {
            //Ascending Sort
            if(list[j] < list[i])
            {
                // Verbose: Output modifications
                if(verbose == 'V')
                {
                    int k;
                    for( k=0; k<size; k++)
                    {
                        if( k == i )
                            printf("\033[1;31m%d \033[0m", list[k]);
                        else if( k == j )
                            printf("\033[1;32m%d \033[0m", list[k]);
                        else
                            printf("%d ", list[k]);
                    }
                    printf("\n");

                }

                list[j]  = list[j] + list[i];
                list[i]  = list[j] - list[i];
                list[j]  = list[j] - list[i];
            }
        }
    }
}

int main()
{
    int arr[] = {3, 7, 8, 1, 9, 10, 2, 6};
    unsigned int size = sizeof(arr)/sizeof(int);

    selection_sort(arr, size, 'V');
}