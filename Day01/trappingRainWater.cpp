#include<bits/stdc++.h>
using namespace std;


void striker()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int prev_wall = arr[0];
    int prev_ind = 0;
    int ans = 0, tmp = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < prev_wall)
        {
            ans += prev_wall - arr[i];
            tmp += prev_wall - arr[i];
        }
        else
        {
            tmp = 0;
            prev_wall = arr[i];
            prev_ind = i;   
        }
    }
    if (n - 1 > prev_ind)
    {
        ans -= tmp;
        prev_wall = arr[n - 1];
        for (int i = n - 1; i >= prev_ind; i--)
        {
            if (arr[i] < prev_wall)
                ans += prev_wall - arr[i];
            else
                prev_wall = arr[i];
        }
    }
    cout << "Maximum Water : " << ans;
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
        //cout<<"#Case: "<<i+1<<endl;
        striker();
        cout << endl;
    }
    return 0;
}