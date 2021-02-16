#include<bits/stdc++.h>
using namespace std;



//#define int long long
// const int MOD = 1000000007;


int totalPath(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;
    int sum = totalPath(m - 1, n) + totalPath(m, n - 1);
    return sum;
}


void striker()
{
    int m, n;
    cin >> m >> n;
    cout << totalPath(m, n);
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; i++)
    {
        // cout << "#Case: " << i + 1 << endl;
        striker();
        // cout << endl;
    }
    return 0;
}