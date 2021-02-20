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



bool chckMirror(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 == NULL || root2 == NULL)
        return false;
    if (root1 -> data == root2 -> data)
        return (chckMirror(root1 -> left, root2 ->right) && chckMirror(root1 -> right, root2 -> left));
    else
        return false;
}


void striker()
{
    Node *root1 = new Node(1); 
    Node *root2 = new Node(1); 
    root1 -> left = new Node(2); 
    root1 -> right = new Node(3); 
    root1 -> left -> left  = new Node(4); 
    root1 -> left -> right = new Node(5); 
  
    root2 -> left = new Node(3);
    root2 -> right = new Node(2); 
    root2 -> right -> left = new Node(5); 
    root2 -> right -> right = new Node(4); 

    if (chckMirror(root1, root2))
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