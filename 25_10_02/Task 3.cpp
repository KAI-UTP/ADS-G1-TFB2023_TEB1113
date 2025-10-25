#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cout << "Please enter number of rows and columns: ";
    cin >> r >> c;

    vector<vector<int>> mat(r, vector<int>(c));
    cout << "Please enter the matrix (0s and 1s only):\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

    vector<int> row(r, 0), col(c, 0);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (mat[i][j] == 1)
                row[i] = col[j] = 1;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (row[i] == 1 || col[j] == 1)
                mat[i][j] = 1;

    cout << "The modified matrix is:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}
