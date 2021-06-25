#include<bits/stdc++.h>
using namespace std;
#define MAX 5


void findPathRec(int m[MAX][MAX], vector<string> &res, int n, vector<vector<int>> &vis, int row, int col, string s = "")
{
    if (row < 0 || col < 0 || row >= n || col >= n || m[row][col] == 0 || vis[row][col] == 1)
        return;
    if (row == n - 1 && col == n - 1)
    {
        res.push_back(s);
        return;
    }
    vis[row][col] = 1;
    findPathRec(m, res, n, vis, row + 1, col, s + "D");
    findPathRec(m, res, n, vis, row, col - 1, s + "L");
    findPathRec(m, res, n, vis, row, col + 1, s + "R");
    findPathRec(m, res, n, vis, row - 1, col, s + "U");
    vis[row][col] = 0;
} 


vector<string> path(int m[MAX][MAX], int n)
{
    vector<string> res;
    vector<vector<int>> vis(MAX, vector<int> (MAX, 0));
    findPathRec(m, res, n, vis, 0, 0);
    return res;
}


void striker()
{
    int n;
    cin >> n;
    int mat[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    vector<string> result = path(mat, n);
    if (result.size() == 0)
        cout << -1;
    else
    {
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    }
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