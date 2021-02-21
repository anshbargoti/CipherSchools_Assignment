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


int maxSum(Node *root, int &ans)
{
	if (root == NULL)
		return 0;
	int curr_s = root -> data + maxSum(root -> left, ans) + maxSum(root -> right, ans);
	ans = max(ans, curr_s);
	return curr_s;
}


void striker()
{
    Node *root = new Node(1);
    root -> left = new Node(-2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(-6);
    root -> right -> right = new Node(2);
    int ans = INT_MIN;
    maxSum(root, ans);
    cout << ans;
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