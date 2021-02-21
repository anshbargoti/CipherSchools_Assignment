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


Node *makeTree(int in[], int pos[], int st, int en, int postIndex)
{
    if (st > en)
        return NULL;
    Node *root = new Node(pos[postIndex]);
    int inIndex = st;
    while (pos[postIndex] != in[inIndex])
        inIndex++;
    root -> left = makeTree(in, pos, st, inIndex - 1, postIndex - (en - inIndex) - 1);
    root -> right = makeTree(in, pos, inIndex + 1, en, postIndex - 1);
    return root;
}



void levelorder(Node *head)
{
    if (head == NULL)
        return;
    queue <Node *> q;
    q.push(head);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp -> data << " ";
        if (temp -> left)
            q.push(temp -> left);
        if (temp -> right)
            q.push(temp -> right);
    }
}

void striker()
{
    int in[] = {9, 3, 15, 20, 7};
    int pos[] = {9, 15, 7, 20, 3};
    int n = sizeof(in) / sizeof(in[0]);
    Node *head = makeTree(in, pos, 0, n - 1, n - 1);
    levelorder(head);
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