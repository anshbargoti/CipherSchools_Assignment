#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int preIndex = 0;


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


Node *makeTree(int in[], int pre[], int st, int en)
{
    if (st > en)
        return NULL;
    Node *root = new Node(pre[preIndex++]);
    int inIndex;
    for (int i = st; i <= en; i++)
    {
        if (in[i] == root -> data)
        {
            inIndex = i;
            break;
        }
    }
    root -> left = makeTree(in, pre, st, inIndex - 1);
    root -> right = makeTree(in, pre, inIndex + 1, en);
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
    int in[] = {20, 10, 40, 30, 50};
    int pre[] = {10, 20, 30, 40, 50};
    int n = sizeof(in) / sizeof(in[0]);
    Node *head = makeTree(in, pre, 0, n - 1);
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