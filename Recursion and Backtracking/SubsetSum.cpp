#include<bits/stdc++.h>
using namespace std;



//#define int long long
// const int MOD = 1000000007;



void generateSubset(int arr[], int n, vector<int> vc, int sum)
{
    if (sum == 0)
    {
        for (int x : vc)
            cout << x << " ";
        cout << endl;
        return;
    }
    if (n == 0)
        return;
    generateSubset(arr, n - 1, vc, sum);
    if (sum - arr[n - 1] >= 0)
    {
        vc.push_back(arr[n - 1]);
        generateSubset(arr, n - 1, vc, sum - arr[n - 1]);
    }
}


void striker()
{
    int n, targetSum;
    cin >> n >> targetSum;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> vc;
    generateSubset(arr, n, vc, targetSum);
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