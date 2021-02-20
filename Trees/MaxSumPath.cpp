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


int getSum(Node *root, int &res)
{
    if (root == NULL)
        return 0;
    int left_s = getSum(root -> left, res);
    int right_s = getSum(root -> right, res);
    res = max(res, left_s + right_s + root -> data);
    return (root -> data + max(left_s, right_s));
}


void striker()
{
    Node *root = new Node(-10);
    root -> left = new Node(9);
    root -> right = new Node(20);
    root -> right -> left = new Node(15);
    root -> right -> right = new Node(7);
    int res = 0;
    getSum(root, res);
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