#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int row = 3, col = 3;

    int mat[3][3] = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    int arr[row * col];
    int r = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[r] = mat[i][j];
            r++;
        }
    }


    sort(arr, arr + row * col);


    int sortedMat[row][col];
    r = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sortedMat[i][j] = arr[r];
            r++;
        }
    }


    cout << "Sorted Matrix:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << sortedMat[i][j] << " ";
        }
        cout << endl;
    }
    
    int mid = (row * col) / 2;
    int median = arr[mid];
    
    cout << "Median = " << median << endl;
    

    return 0;
}
