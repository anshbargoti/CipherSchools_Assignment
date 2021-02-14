#include<bits/stdc++.h>
using namespace std;



//#define int long long
// const int MOD = 1000000007;



void striker()
{
    int n, x;
    cin >> n >> x;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    if (x < arr[0][0] || x > arr[n - 1][n - 1])
    {
        cout << "Element not found";
        return;
    }
    int i = 0, j = n - 1;
    while (i <= n - 1 && j >= 0)
    {
        if (arr[i][j] == x)
        {
            cout << "Element found at position ("<< i << "," << j << ")";
            return;
        }
        else if (arr[i][j] < x)
            i++;
        else
            j--;
    }
    cout << "Element not found";
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
        //cout<<"#Case: "<<i+1<<endl;
        striker();
        // cout << endl;
    }
    return 0;
}