#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define Limon() ios::sync_with_stdio(false); cin.tie(nullptr);

int n;
vector<int> queen;

bool safe(int row, int col) {
    for (int r = 0; r < row; ++r) {
        int c = queen[r];
        if (c == col) return false;
        if (abs(c - col) == abs(r - row)) return false;
    }
    return true;
}

bool solve(int row) {
    if (row == n) return true;
    for (int col = 0; col < n; ++col) {
        if (!safe(row, col)) continue;
        queen[row] = col;
        if (solve(row + 1)) return true;
        queen[row] = -1;
    }
    return false;
}

int main() {
    Limon();
    if (!(cin >> n)) return 0;
    queen.assign(n, -1);

    if (solve(0)) {
        cout << "YES\n";
        for (int r = 0; r < n; ++r) {
            cout << (r + 1) << " " << (queen[r] + 1) << "\n";
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}

