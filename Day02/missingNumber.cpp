#include<bits/stdc++.h>
using namespace std;


void striker()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int a1 = 0, a2 = 0;
    for (int i = 0; i < n; i++)
    {
        a2 = a2 ^ (i + 1);
        a1 = a1 ^ (arr[i]);
    }
    a2 = a2 ^ (n + 1);
    cout << "Missing Element : " << (a1 ^ a2);
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