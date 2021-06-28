#include<bits/stdc++.h>
using namespace std;


void recur(string s, int k, string &res)
{
    if (k == 0)
        return;
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (s[j] > s[j]) 
            {
                swap(s[i], s[j]);
                if (s.compare(res) > 0)
                    res = s;
                recur(s, k - 1, res);
                swap(s[i], s[j]);
            }
        }
    }
}


void striker()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    string res = s;
    recur(s, k, res);
    cout << res;
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