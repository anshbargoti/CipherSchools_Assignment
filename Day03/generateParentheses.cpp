#include<bits/stdc++.h>
using namespace std;


void gener(vector<string> &res, string s, int n, int open, int close)
{
    if (open == n && close == n)
    {
        res.push_back(s);
        return;
    }
    if (open < n)
        gener(res, s + "(", n, open + 1, close);
    if (open > close)
        gener(res, s + ")", n, open, close + 1);
}

void striker()
{
    int n;
    cin >> n;
    vector<string> res;
    gener(res, "", n, 0, 0);
    for (auto x : res)
        cout << x << endl;
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