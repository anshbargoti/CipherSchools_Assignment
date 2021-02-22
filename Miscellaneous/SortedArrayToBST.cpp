#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// #define int long long
// const int MOD = 1000000007;



struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};



Node *makeTree(int st, int en, int arr[])
{
	if (st > en)
		return NULL;
	int mid = (st + en) / 2;
	Node *head = new Node(arr[mid]);
	head -> left = makeTree(st, mid - 1, arr);
	head -> right = makeTree(mid + 1, en, arr);
	return head;
}


void inord(Node *head)
{
	if (head == NULL)
		return;
	inord(head -> left);
	cout << head -> data << " ";
	inord(head -> right);
}

void striker()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = makeTree(0, n - 1, arr);
    inord(head);
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