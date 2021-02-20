#include<bits/stdc++.h>
using namespace std;
#define endl "\n"



// #define int long long
// const int MOD = 1000000007;



struct Node
{
    int data;
    Node *left, *right;
    int hd;
    Node (int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        hd = 0;
    }
};



void leftView(Node *head)
{
    if (head == NULL)
        return;
    queue <Node *> q;
    q.push(head);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr -> data << " ";
            if (curr -> left)
                q.push(curr -> left);
            if (curr -> right)
                q.push(curr -> right);
        }
    }
}


void rightView(Node *head)
{
    if (head == NULL)
        return;
    queue <Node *> q;
    q.push(head);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == count - 1)
                cout << curr -> data << " ";
            if (curr -> left)
                q.push(curr -> left);
            if (curr -> right)
                q.push(curr -> right);
        }
    }
}


void topView(Node *head)
{
    if (head == NULL)
        return;
    queue <Node *> q;
    map <int, int> mp;
    q.push(head);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        int hd = curr -> hd;
        if (mp.count(hd) == 0)
            mp[hd] = curr -> data;
        if (curr -> left)
        {
            q.push(curr -> left);
            curr -> left -> hd = hd - 1;
        }
        if (curr -> right)
        {
            q.push(curr -> right);
            curr -> right -> hd = hd + 1;
        }
    }

    for (auto x : mp)
        cout << x.second << " ";
}


void bottomView(Node *head)
{
    if (head == NULL)
        return;
    queue <Node *> q;
    map <int, int> mp;
    q.push(head);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        int hd = curr -> hd;
        mp[hd] = curr -> data;
        if (curr -> left)
        {
            q.push(curr -> left);
            curr -> left -> hd = hd - 1;
        }
        if (curr -> right)
        {
            q.push(curr -> right);
            curr -> right -> hd = hd + 1;
        }
    }

    for (auto x : mp)
        cout << x.second << " ";
}


void striker()
{
    Node *root = new Node(5);
    root -> left = new Node(10);
    root -> right = new Node(15);
    root -> left -> left = new Node(20);
    root -> left -> right = new Node(25);
    root -> right -> left = new Node(30);
    root -> right -> right = new Node(35);
    leftView(root);
    cout << endl;
    rightView(root);
    cout << endl;
    topView(root);
    cout << endl;
    bottomView(root);
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