#include<bits/stdc++.h>
using namespace std;



//#define int long long
// const int MOD = 1000000007;



struct Node 
{
    int data;
    Node *next;
    Node (int x)
    {
        data = x;
        next = NULL;
    }
};


void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr -> data;
        cout << "->";
        if (curr -> next == NULL)
            cout << "NULL";
        curr = curr -> next;
    }
}


Node *mergesort(Node *root1, Node *root2)
{
    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;
    if (root1 -> data <= root2 -> data)
    {
        root1 -> next = mergesort(root1 -> next, root2);
        return root1;
    }
    else
    {
        root2 -> next = mergesort(root2 -> next, root1);
        return root2;
    }
}

Node *mergeall(Node *root[], int limit)
{
    int ind = 0;
    while (ind < limit - 1)
    {
        root[ind + 1] = mergesort(root[ind], root[ind + 1]);
        root[ind] = nullptr;
        ++ind;
    }
    return root[limit - 1];
}


void striker()
{
    int k, n;
    cin >> k >> n;
    Node *root[k];
    Node *tail = NULL;
    for (int i = 0; i < k; i++)
    {
        int firstval;
        cin >> firstval;
        root[i] = new Node(firstval);
        tail = root[i];
        for (int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            tail -> next = new Node(x);
            tail = tail -> next;
        }
    }
    Node *head = mergeall(root, k);
    printlist(head);
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
        // cout << "#Case: " << i + 1 << endl;
        striker();
        cout << endl;
    }
    return 0;
}