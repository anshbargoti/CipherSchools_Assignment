#include<bits/stdc++.h>
using namespace std;



//#define int long long
// const int MOD = 1000000007;


void totalPath(int m, int n, int &tot)
{
    if (m == 1 || n == 1)
    {
        tot++;
        return;
    }
    totalPath(m - 1, n, tot);
    totalPath(m, n - 1, tot);
}


void striker()
{
    int m, n;
    cin >> m >> n;
    int tot = 0;
    totalPath(m, n, tot);
    cout << tot;
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