#include<bits/stdc++.h>
using namespace std;



//#define int long long
// const int MOD = 1000000007;


int fibn(int n, int prev = 0, int curr = 1)
{
    if (n == 0)
        return prev;
    else if (n == 1)
        return curr;
    return fibn(n - 1, curr, prev + curr);
}

void striker()
{
    int n;
    cin >> n;
    cout << fibn(n);
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
        cout << endl;
    }
    return 0;
}