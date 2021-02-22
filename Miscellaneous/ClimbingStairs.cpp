#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int mod = 1000000007;


// #define int long long



long long totWays(int m)
{
    if (m == 0 || m == 1)
        return m;
    long long prev_prev = 1, prev = 1, curr;
    for (int i = 2; i <= m; i++)
    {
        curr = (prev % mod + prev_prev % mod) % mod;
        prev_prev = prev;
        prev = curr;
    }
    return curr;
}


void striker()
{
    cout << totWays(3) << " " << totWays(5) << " " << totWays(10);
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