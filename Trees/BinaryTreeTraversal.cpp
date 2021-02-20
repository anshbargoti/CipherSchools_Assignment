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



void inorder(Node *head)
{
    if (head == NULL)
        return;
    inorder(head -> left);
    cout << head -> data << " ";
    inorder(head -> right);
}

void preorder(Node *head)
{
    if (head == NULL)
        return;
    cout << head -> data << " ";
    preorder(head -> left);
    preorder(head -> right);
}

void postorder(Node *head)
{
    if (head == NULL)
        return;
    postorder(head -> left);
    postorder(head -> right);
    cout << head -> data << " ";
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
    Node *root = new Node(5);
    root -> left = new Node(10);
    root -> right = new Node(15);
    root -> left -> left = new Node(20);
    root -> left -> right = new Node(25);
    root -> right -> left = new Node(30);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    levelorder(root);
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