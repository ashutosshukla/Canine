#include <bits/stdc++.h>
using namespace std;
int count_unique_squares(vector<string> &matrix, int K) {
    int n = matrix.size();
    int m = matrix[0].size();
    set<string> unique_squares;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // check if the current square contains only trees
            if (matrix[i][j] == '*' && (i == 0 || matrix[i-1][j] == '.') && (j == 0 || matrix[i][j-1] == '.') && (i == n-1 || matrix[i+1][j] == '.') && (j == m-1 || matrix[i][j+1] == '.')) {
                // check if the current square is a unique square
                string square = "";
                for (int x = i-K/2; x <= i+K/2; x++) {
                    for (int y = j-K/2; y <= j+K/2; y++) {
                        if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] == '*') {
                            square += '*';
                        } else {
                            square += '.';
                        }
                    }
                }
                unique_squares.insert(square);
            }
        }
    }
    return unique_squares.size();
}
int main() {
    int n, m, q, k;
    cin >> n >> m;
    vector<string> matrix(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> k;
        cout << count_unique_squares(matrix, k) << endl;
    }
    return 0;
}
