#include <bits/stdc++.h>
using namespace std;

int findMedian(const vector<vector<int>>& mat) {
    int r = mat.size();
    int c = mat[0].size();
    int target = (r * c + 1) / 2;
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < r; i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][c - 1]);
    }
    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 0; i < r; i++)
            count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        if (count < target) low = mid + 1;
        else high = mid;
    }
    return low;
}

int main() {
    int r, c;
    cout << "Please enter number of rows and columns: ";
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c));

    cout << "Please enter the elements of the matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

    cout << "The median of the matrix is: " << findMedian(mat);
    return 0;
}
