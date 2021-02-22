#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// #define int long long
// const int MOD = 1000000007;



// Allowed move => Down or Right

void striker()
{
    int mat[3][3] = {{1,2,3},{4,8,2},{1,5,3}};
    int m = 3;
    int n = 3; 
    for (int i = 1; i < n; i++)
    	mat[0][i] += mat[0][i - 1];
    
    for (int i = 1; i < m; i++)
    	mat[i][0] += mat[i-1][0];

    for (int i = 1; i < m; i++)
    { 
        for (int j = 1; j < n; j++)
        {
            mat[i][j] += min(mat[i-1][j], mat[i][j-1]);
        }
    }
    cout << mat[m - 1][n - 1];
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        // cout << "#Case: "<< i + 1 << endl;
        striker();
        // cout << endl;
    }
    return 0;
}
