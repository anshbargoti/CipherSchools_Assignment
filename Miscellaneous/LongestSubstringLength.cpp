#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// #define int long long
// const int MOD = 1000000007;




int longestSub(string s, int n)
{
    int ans = 0;
    vector<int> ind(256, -1);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int x = ind[s[i]] + 1;
        if (x > k)
            k = x;
        ans = max(ans, i - k + 1);
        ind[s[i]] = i;
    }
    return ans;
}


void striker()
{
    string s = "ABDEFGABEF";
    int n = s.size();
    cout << longestSub(s, n);
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        // cout << "#Case: "<< i + 1 << endl;
        striker();
        // cout << endl;
    }
    return 0;
}