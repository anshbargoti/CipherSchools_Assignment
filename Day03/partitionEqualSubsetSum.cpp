#include<bits/stdc++.h>
using namespace std;


void striker()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
        
    if (sum % 2 != 0)
    {
        cout << "Partition Not Possible";
        return;
    }
    bool dp[n + 1][(sum / 2) +1];
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum / 2 + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum / 2; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[n][sum / 2])
        cout << "Partition Possible";
    else
        cout << "Partition Not Possible";
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        // cout << "#Case: " << i + 1 << endl;
        striker();
        cout << endl;
    }
    return 0;
}