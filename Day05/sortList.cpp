#include<bits/stdc++.h>
using namespace std;


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


Node *mergesort(Node *temp1, Node *temp2)
{
    Node *curr = new Node(0);
    Node *temp = curr;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 -> data < temp2 -> data)
        {
            temp -> next = temp1;
            temp1 = temp1 -> next;
        }
        else
        {
            temp -> next = temp2;
            temp2 = temp2 -> next;
        }
        temp = temp -> next;
    }
    if (temp1 != NULL)
        temp -> next = temp1;
    if (temp2 != NULL)
        temp -> next = temp2;
    return curr -> next;
}

Node *sortlist(Node *root)
{
    if (root == NULL || root -> next == NULL)
        return root;
    Node *slow = root;
    Node *fast = root -> next;
    while (fast -> next != NULL && fast -> next -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    Node *mid = slow -> next;
    slow -> next = NULL;
    Node *l = sortlist(root);
    Node *r = sortlist(mid);
    return mergesort(l, r);
}


void striker()
{
    int n;
    cin >> n;
    Node *root = NULL, *tail = NULL;
    int firstval;
    cin >> firstval;
    root = new Node(firstval);
    tail = root;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        tail -> next = new Node(x);
        tail = tail -> next;
    }
    Node *head = sortlist(root);
    printlist(head);
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        // cout << "#Case: " << i + 1 << endl;
        striker();
        cout << endl;
    }
    return 0;
}