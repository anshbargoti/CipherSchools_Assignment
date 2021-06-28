#include<bits/stdc++.h>
using namespace std;


void striker()
{
    int n;
    cin >> n;
    if (n < 0)
    {
        cout << -1;
        return;
    }
 
    int count = 0;
 
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;
 
    cout << count;
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