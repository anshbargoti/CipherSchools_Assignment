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


int getDiam(Node *root, int &res)
{
    if (root == NULL)
        return 0;
    int left_h = getDiam(root -> left, res);
    int right_h = getDiam(root -> right, res);
    res = max(res, left_h + right_h);
    return (1 + max(left_h, right_h));
}


void striker()
{
    Node *root = new Node(10);
    root -> left = new Node(11);
    root -> right = new Node(12);
    root -> left -> left = new Node(13);
    root -> left -> right = new Node(14);
    root -> right -> left = new Node(15);
    root -> right -> right = new Node(16);
    int res = 0;
    getDiam(root, res);
    cout << res;
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