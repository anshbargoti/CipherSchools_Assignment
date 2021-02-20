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


Node *lca(Node *root, int n1, int n2, bool &a, bool &b)
{
    if (root == NULL)
        return NULL;
    if (root -> data == n1)
    {
        a = true;
        return root;
    }
    if (root -> data == n2)
    {
        b = true;
        return root;
    }

    Node *l_lca = lca(root -> left, n1, n2, a, b);
    Node *r_lca = lca(root -> right, n1, n2, a, b);

    if (l_lca != NULL && r_lca != NULL)
        return root;
    if (l_lca != NULL)
        return l_lca;
    else
        return r_lca;
}


bool chck(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root -> data == x || chck(root -> left, x) ||  chck(root -> right, x))
        return true;
    return false;
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
    Node *ans = NULL;
    bool a = false, b = false;
    int n1 = 14, n2 = 10;
    ans = lca(root, n1, n2, a, b);
    bool check = ( (a && b) || (a && chck(ans, n2) ) || (b && chck(ans, n1)) );
    if (check)
        cout << ans -> data;
    else
        cout << "Not Present";

    cout << endl;
    a = false, b = false;

    n1 = 11, n2 = 13;
    ans = lca(root, n1, n2, a, b);
    check = ( (a && b) || (a && chck(ans, n2) ) || (b && chck(ans, n1)) );
    if (check)
        cout << ans -> data;
    else
        cout << "Not Present";
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