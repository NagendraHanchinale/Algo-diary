// minimum between the ranges ( L , R )

#include <bits/stdc++.h>
using namespace std;

const int MAXL = 1e6;
const int K = 25; 
int s[K + 1][MAXL];


int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0;i < n; ++i)cin >> a[i];
    copy(a.begin(),a.end(),s[0]);
    
    for(int i = 1;i <= K; ++i){
        for(int j = 0;j + (1 << i) <= n; ++j){
            s[i][j] = min(s[i-1][j],s[i-1][j + (1 << (i - 1))]);
        }
    }
    
    while(m--){
        int l,r;
        cin >> l >> r;
        int len = log2(r - l + 1);
        cout << min(s[len][l],s[len][r - (1 << len) + 1]) << endl;
    }
    

    return 0;
}
