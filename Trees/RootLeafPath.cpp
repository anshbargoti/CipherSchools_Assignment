#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// #define int long long
// const int MOD = 1000000007;



struct Node
{
    int data;
    Node *left, *right;
    Node (int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};



void path(Node *root, vector<string> &ans, string curr)
{
    if (root == NULL)
        return;
    if (root -> left == NULL && root -> right == NULL)
    {
        curr += (to_string(root -> data));
        ans.push_back(curr);
    }
    path(root -> left, ans, curr + (to_string(root -> data)) + "->");
    path(root -> right, ans, curr + (to_string(root -> data)) + "->");
}


void striker()
{
    Node *root = new Node(10);
    root -> left = new Node(8);
    root -> right = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(2);
    vector<string> ans;
    string curr = "";
    path(root, ans, curr);
    for (auto x : ans)
        cout << x << endl;
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