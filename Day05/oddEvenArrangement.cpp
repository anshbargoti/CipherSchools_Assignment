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


void arrange(Node *root)
{
    Node *curr_even = root;
    Node *curr_odd = root -> next;
    Node *first_odd = root -> next;
    if (root == NULL)
    {
        cout << "No element present";
        return;
    }
    if (root -> next == NULL)
    {
        printlist(root);
        return;
    }
    while (curr_even -> next != NULL)
    {
        if (curr_odd -> next == NULL)
            break;
        curr_even -> next = curr_even -> next -> next;
        curr_even = curr_even -> next;
        curr_odd -> next = curr_odd -> next -> next;
        curr_odd = curr_odd -> next;
    }
    curr_even -> next = first_odd;
    printlist(root);
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
    arrange(root);
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