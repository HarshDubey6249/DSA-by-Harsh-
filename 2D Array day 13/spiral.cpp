#include <iostream>
using namespace std;

int matrix(int mat[][4], int n, int m)
{
    int scol = 0, srow = 0;
    int ecol = m - 1, erow = n - 1;
    
    while (srow <= erow && scol <= ecol)
    {
    // top
        for (int i = scol; i <= ecol; i++)
        {
            cout << mat[srow][i]<<" ";
        }
        // right
        for (int j = srow +1; j <= erow; j++)
        {
            cout << mat[j][ecol]<<" ";
        }
        // bottom
        for (int i = ecol - 1; i >= scol; i--)
        {
            if(srow==erow){
                break;
            }
            cout << mat[erow][i]<<" ";
        }
        // left
        for (int j = erow - 1; j >= srow + 1; j--)
        {
            if(scol==ecol){
                break;
            }
            cout << mat[j][scol]<<" ";
        }

        scol++,srow++,ecol--,erow--;
    }
}
int main()
{
    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    int n = 4, m = 4;

    matrix(arr,4,4);

    return 0;
}