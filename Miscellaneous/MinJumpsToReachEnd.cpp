#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int mod = 1000000007;


// #define int long long



int minjump(int arr[], int n)
{
    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    int maxR = arr[0], step = arr[0], jump = 1;          
    
    for (int i = 1; i < n; i++)
    {
        
        if (i == n - 1)
            return jump;
        maxR = max(maxR, i + arr[i]);
        step--;
        if (step == 0)
        {
            ++jump;
            if (i >= maxR)
                return -1;
            step = maxR - i;
        }
    }
    return -1;
}


void striker()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minjump(arr, n);
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