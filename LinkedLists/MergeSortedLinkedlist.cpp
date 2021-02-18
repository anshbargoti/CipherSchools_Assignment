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


void sortll(Node *root1, Node *root2)
{
    Node *curr1 = root1;
    Node *curr2 = root2;
    Node *head = NULL;
    if (curr1 -> data < curr2 -> data)
    {
        head = new Node(curr1 -> data);
        curr1 = curr1 -> next;
    }
    else
    {
        head = new Node(curr2 -> data);
        curr2 = curr2 -> next;
    }
    Node *tail = head;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1 -> data < curr2 -> data)
        {
            tail -> next = new Node(curr1 -> data);
            tail = tail -> next;
            curr1 = curr1 -> next;
        }
        else
        {
            tail -> next = new Node(curr2 -> data);
            tail = tail -> next;
            curr2 = curr2 -> next;
        }
    }
    while (curr1 != NULL)
    {
        tail -> next = new Node(curr1 -> data);
        tail = tail -> next;
        curr1 = curr1 -> next;
    }
    while (curr2 != NULL)
    {
        tail -> next = new Node(curr2 -> data);
        tail = tail -> next;
        curr2 = curr2 -> next;
    }
    printlist(head);
}


void striker()
{
    int n, m;
    cin >> n >> m;
    Node *root1 = NULL, *root2 = NULL, *tail = NULL;
    int firstval;
    cin >> firstval;
    root1 = new Node(firstval);
    tail = root1;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        tail -> next = new Node(x);
        tail = tail -> next;
    }
    cin >> firstval;
    root2 = new Node(firstval);
    tail = root2;
    for (int i = 1; i < m; i++)
    {
        int x;
        cin >> x;
        tail -> next = new Node(x);
        tail = tail -> next;
    }
    sortll(root1, root2);
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