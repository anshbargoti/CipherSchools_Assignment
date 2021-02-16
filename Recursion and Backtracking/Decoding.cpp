#include<bits/stdc++.h>
using namespace std;



//#define int long long
// const int MOD = 1000000007;


int decode(string s, int n)
{
    if (s[0] == '0')
        return 0;
    int a = 1, b = 1, c = 0;
    for (int i = 2; i <= n; i++)
    {
        c = ((int)(s[i - 1] != '0') *  b);
        c += ( (int)((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] < '7')) * a );
        a = b;
        b = c;
    }
    return b;
}


void striker()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << decode(s, n);
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