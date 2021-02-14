#include<bits/stdc++.h>
using namespace std;



//#define int long long
// const int MOD = 1000000007;



void striker()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int pos_str = 0, pos_end = n - 1;
    while (pos_str < pos_end)
    {
        if (arr[pos_str] == 0)
            pos_str++;
        else if (arr[pos_str] == 1)
        {
            if (arr[pos_end] == 0)
                swap(arr[pos_str], arr[pos_end]);
            pos_end--;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
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