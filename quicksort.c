#include <stdio.h>

void quicksort( int * A, unsigned int l, unsigned int r )
{
    if (r-l <= 1) return; // Base case (empty or singleton)

    // Partition with respect to pivot, A[l]
    
    // OG STRATERGY
    unsigned int yellow = l+1;
    unsigned int green = r-1;
    while( 1 )
    {
        // Find violating yellow and green
        while (A[yellow] <= A[l]) yellow++;
        while (A[green] > A[l]) green--;
        if (green < yellow) break;
        int temp = A[yellow];
        A[yellow] = A[green];
        A[green]  = temp;
        yellow++; green--;
    }

    // NEW STRATERGY
    // unsigned int yellow = l+1;
    // for (unsigned int green = l+1; green < r; green++)
    // {        
    //     if (A[green] <= A[l])
    //     {
    //         // swap upper element with lower element
    //         int temp = A[yellow];
    //         A[yellow] = A[green];
    //         A[green]  = temp;
    //         yellow++;
    //     }
    // }
        
        // Move pivot into place
        yellow--;
        int temp = A[yellow];
        A[yellow] = A[l];
        A[l] = temp;

    // Recursively sort left and right sections
    quicksort(A, l, yellow);
    quicksort(A, yellow+1, r);
}

int main()
{
    int X[] = {4, 6, 3, 2, 8, 5, 1};
    for (int i=0; i<7; i++) printf("%d ", X[i]); printf("\n");
    quicksort(X, 0, 7);
    for (int i=0; i<7; i++) printf("%d ", X[i]); printf("\n");
    return 0;
}
