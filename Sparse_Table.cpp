// Program to compute the minimum between ranges (L, R) using Sparse Table (O(1) query)

#include <bits/stdc++.h>
using namespace std;

const int MAXL = 1e6;       // Max size of array
const int K = 25;           // log2(MAXL) ~ 20, slightly larger to be safe
int s[K + 1][MAXL];         // Sparse table: s[i][j] stores min in range [j, j + 2^i - 1]

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    // Initialize the 0-th level of sparse table with original array
    copy(a.begin(), a.end(), s[0]);

    // Build the sparse table
    for(int i = 1; i <= K; ++i) {
        for(int j = 0; j + (1 << i) <= n; ++j) {
            // Combine two overlapping segments of size 2^(i-1)
            s[i][j] = min(s[i - 1][j], s[i - 1][j + (1 << (i - 1))]);
        }
    }

    // Answer each query in O(1) using sparse table
    while(m--) {
        int l, r;
        cin >> l >> r;

        int len = log2(r - l + 1); // largest power of 2 within the range length

        // Minimum is the min of two overlapping ranges of length 2^len
        cout << min(s[len][l], s[len][r - (1 << len) + 1]) << endl;
    }

    return 0;
}

