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



bool chck(Node *root, Node *&prev)
{
    if (root == NULL)
        return true;
    if (chck(root -> left, prev) == false) 
        return false;  
    if (prev != NULL && root -> data <= prev -> data) 
        return false;
    prev = root; 
    if (chck(root -> right, prev) == false)
        return false;
    return true;
}


void striker()
{
    Node *root = new Node(3);  
    root -> left = new Node(2);  
    root -> right = new Node(5);  
    root -> left -> left = new Node(1);  
    root -> left -> right = new Node(3); 
    Node *prev = NULL; 
    if (chck(root, prev))
        cout << "YES";
    else
        cout << "NO";
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