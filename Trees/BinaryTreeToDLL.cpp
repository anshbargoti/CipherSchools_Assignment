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


Node *DLL(Node *root)
{
    if (root == NULL)
        return NULL;
    static Node *prev = NULL;
    Node *head = DLL(root -> left);
    if (prev == NULL)
        head = root;
    else
    {
        root -> left = prev;
        prev -> right = root;
    }
    prev = root;
    DLL(root -> right);
    return head;
}


void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr -> data << " ";
        curr = curr -> right;
    }
}

void striker()
{
    Node *root = new Node(10);
    root -> left = new Node(5);
    root -> right = new Node(20);
    root -> right -> left = new Node(30);
    root -> right -> right = new Node(35);
    Node *ans = DLL(root);
    printlist(ans);
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