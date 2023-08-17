#include <iostream>
#include <string.h>

#define R 5
#define C 5
using namespace std;

int H = 8;
int W = 5;

int Piece_H = 5;
int Piece_W = 5;

int TetrisBoard[8][5];

int Piece[R][C]{
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0}
};

int row, col;

void rotatematrix(int m, int n, int mat[R][C])
{
    int row = 0, col = 0;
    int prev, curr;

    /* row - Starting row index
       m - ending row index
       col - starting column index
       n - ending column index
       i - iterator */
    while (row < m && col < n)
    {
        if (row + 1 == m ||
            col + 1 == n)
            break;

        // Store the first element of 
        // next row, this element will 
        // replace first element of current 
        // row 
        prev = mat[row + 1][col];

        /* Move elements of first row from
           the remaining rows */
        for (int i = col; i < n; i++)
        {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        /* Move elements of last column
           from the remaining columns */
        for (int i = row; i < m; i++)
        {
            curr = mat[i][n - 1];
            mat[i][n - 1] = prev;
            prev = curr;
        }
        n--;

        /* Move elements of last row from
           the remaining rows */
        if (row < m)
        {
            for (int i = n - 1; i >= col; i--)
            {
                curr = mat[m - 1][i];
                mat[m - 1][i] = prev;
                prev = curr;
            }
        }
        m--;

        /* Move elements of first column from
           the remaining rows */
        if (col < n)
        {
            for (int i = m - 1; i >= row; i--)
            {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }

    // Print rotated matrix 
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}


int main()
{

    rotatematrix(R, C, Piece);
}
