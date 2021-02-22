#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// #define int long long
// const int MOD = 1000000007;



struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};



void rangeQ(Node *root, int l, int r)
{
    if (root == NULL)
        return;
    if (root -> data > l)
        rangeQ(root -> left, l, r);
    if (root -> data >= l && root -> data <= r)
        cout << root -> data << " ";
    if (root -> data < r)
        rangeQ(root -> right, l, r);
}


void striker()
{
    Node *root = new Node(30); 
    root -> left = new Node(18); 
    root -> right = new Node(32); 
    root -> left -> left = new Node(14); 
    root -> left -> right = new Node(22);
    int l, r;
    l = 20, r = 35;
    rangeQ(root, l, r);
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