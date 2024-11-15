#include <stdio.h>
// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value
//


int isMagicSquare(int ** square, const int n) {

    // Eliminate the case where 'n' is negative
    if(n < 0) {
        return 0;
    }

    // M is the sum of every row, column,
    // and the main and secondary diagonals
    int M = (n * (n*n + 1))/2;

    // int i, j;
    // TODO: Checking that every row and column add up to M
    int sum = 0; 
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)     // compute sum of row i
        {
            sum += square[i][j]; 
        }

        if (sum != M)
            return 0;               // if the sum is not equal to M then directly return 0 and exit
        sum = 0; 

        for (int j=0; j<n; j++)     // compute sum of column i
        {
            sum += square[j][i]; 
        }

        if (sum != M)
            return 0; 
        sum = 0; 
    }    

    // TODO: Checking that the main and secondary
    // diagonals each add up to M
    // If passed all checks, it is a magic square
    int sum_s = 0; 
    for (int i=0; i<n; i++)
    {
        sum += square[i][i];            // compute the sum of main diagonals
        sum_s += square[n-1-i][i];      // compute the sum of secondary diagonals
    }
    if ((sum != M) | (sum_s != M))
        return 0; 


    return 1;
}

