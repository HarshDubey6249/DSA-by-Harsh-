#include <iostream>
using namespace std;

int main(){
    int cols, rows;

    cout << "enter ypu rows";
    cin >> rows;
    
    cout << "enter ypu cols";
    cin >> cols;

    int **matrix = new int *[rows];

    for (int i = 0; i < rows; i++){
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
        {int x = 1;
            matrix[i][j] = x;
            x++;

            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}