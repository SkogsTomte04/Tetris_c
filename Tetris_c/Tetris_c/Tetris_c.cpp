#include <iostream>
#include <string.h>
#include "Tetris_c.h"
#include <Bits.h>
#define N 4

using namespace std;


void rotateMatrixcounter(int mat[][N])
{
    for (int x = 0; x < N / 2; x++) {

        for (int y = x; y < N - x - 1; y++) {

            int temp = mat[x][y];

            mat[x][y] = mat[y][N - 1 - x];

            
            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];

        
            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];

    
            mat[N - 1 - y][x] = temp;
        }
    }
}
void rotateMatrix(int mat[][N])
{
    for (int x = 0; x < N / 2; x++) {

        for (int y = x; y < N - x - 1; y++) {

            int temp = mat[x][y];

            mat[x][y] = mat[y][N - 1 - x];


            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];


            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];


            mat[N - 1 - y][x] = temp;
        }
    }
}



void displayMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}


int main()
{
    int mat[N][N] = {
    {0,1,0,0},
    {0,1,0,0},
    {0,1,0,0},
    {0,1,0,0}
    };
    bool Debug = true;
    int userinput;
    while (Debug == true) {
        cin >> userinput;

        if (userinput == 1) {
            system("cls");
            rotateMatrixcounter(mat);
            displayMatrix(mat);
            cout << endl;
        }
        if (userinput == 2) {
            rotateMatrix(mat);
            displayMatrix(mat);
        }
    }
    
}
