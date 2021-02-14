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
    int l = 0, mid = 0, h = n - 1;
    while (h >= mid)
    {
        if (arr[mid] == 0)
        {
            swap(arr[l], arr[mid]);
            l++;
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[h]);
            h--;
        }
        else
            mid++;
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