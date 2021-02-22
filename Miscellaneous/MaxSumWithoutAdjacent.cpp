#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int mod = 1000000007;


// #define int long long



int maximz(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    int prev_prev = arr[0];
    int prev = max(arr[0], arr[1]);
    int ans = prev;
    for (int i = 3; i <= n; i++)
    {
        ans = max(prev, prev_prev + arr[i - 1]);
        prev_prev = prev;
        prev = ans;
    }
    return ans;
}


void striker()
{
    int arr[] = {5, 15, 10, 100, 150};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maximz(arr, n);
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