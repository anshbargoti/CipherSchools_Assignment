#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// #define int long long
// const int MOD = 1000000007;



void connect(int arr[], int n)
{
    priority_queue<int, vector<int>,greater<int>> p(arr, arr + n);
    int ans = 0;
    while (p.size() >= 2)
    {
        int f = p.top();
        p.pop();
        int s = p.top();
        p.pop();
        ans = ans + f + s;
        p.push(f + s);
    }
    cout << ans;
}

void striker()
{
    int arr[] = {4, 3, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    connect(arr, n);
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