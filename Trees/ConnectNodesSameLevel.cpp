#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// #define int long long
// const int MOD = 1000000007;



struct Node
{
    int data;
    Node *left, *right, *nextR;
    Node (int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        nextR = NULL;
    }
};


void levelOrder(Node *head)
{
    if (head == NULL)
        return;
    queue <Node *> q;
    q.push(head);
    q.push(NULL);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr != NULL)
        {
            curr -> nextR = q.front();
            if (curr -> left)
                q.push(curr -> left);
            if (curr -> right)
                q.push(curr -> right);
        }
        else if (!q.empty())
            q.push(NULL);
    }
}


void striker()
{
    Node *root = new Node(-10);
    root -> left = new Node(9);
    root -> right = new Node(20);
    root -> right -> left = new Node(15);
    root -> right -> right = new Node(7);
    levelOrder(root);
    cout << root -> left -> nextR -> data << " ";
    cout << root -> right -> left -> nextR -> data;
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