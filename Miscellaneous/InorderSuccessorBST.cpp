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
        left = right = NULL;
    }
};



Node *Insuccsr(Node *root, Node *x)
{
    if (x -> right != NULL)
    {
        Node *curr = x -> right;
        while (curr -> left != NULL)
            curr = curr -> left;
        return curr;
    }
    Node *curr = root;
    Node *ans = NULL;
    while (curr != NULL)
    {
        if (curr -> data > x -> data)
        {
            ans = curr;
            curr = curr -> left;
        }
        else if (curr -> data < x -> data)
            curr = curr -> right;
        else
            break;
    }
    return ans;
}


void striker()
{
    Node *root = new Node(20);
    root -> left = new Node(8);
    root -> right = new Node(22);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(12);
    root -> left -> right -> left = new Node(10);
    root -> left -> right -> right = new Node(14);
    Node *n = root -> left;
    Node *succsr = Insuccsr(root, n);
    if (succsr != NULL)
        cout << succsr -> data << endl;
    else
        cout << "Successor not exist" << endl;
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