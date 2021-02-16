#include<bits/stdc++.h>
using namespace std;



//#define int long long
// const int MOD = 1000000007;


void permutatn(string s, int r, int l = 0)
{
    if (l == r)
    {
        cout << s << " ";
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(s[l], s[i]);
        permutatn(s, r, l + 1);
        swap(s[l], s[i]);
    }

}


void striker()
{
    string s;
    cin >> s;
    int n = s.size();
    permutatn(s, n - 1);
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