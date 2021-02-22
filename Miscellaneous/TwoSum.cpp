#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// #define int long long
// const int MOD = 1000000007;



void findSum(int arr[], int n, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x = target - arr[i];
        if (mp.find(x) != mp.end())
            cout << mp[x] << " " << i;
        mp[arr[i]] = i;
    }
}


void striker()
{
    int arr[] = {2, 7, 11, 15, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 34;
    findSum(arr, n, target);
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