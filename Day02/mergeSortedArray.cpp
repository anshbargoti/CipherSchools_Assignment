#include<bits/stdc++.h>
using namespace std;


void striker()
{
    int n, m;
    cin >> n >> m;
    int arr[n], brr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
        cin >> brr[i];
    map<int, bool> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]] = true;
    for (int i = 0; i < m; i++)
        mp[brr[i]] = true;
    for (auto x : mp)
        cout << x.first << " ";
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