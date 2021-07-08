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



void duplicates(Node *root)
{
    Node* prev = NULL, *curr = NULL, *dummy = new Node(-100);
    int flag = 0;
    dummy -> next = root;
    curr = dummy;
    while (curr != NULL && curr -> next != NULL)
    {
        if (curr -> data == curr -> next -> data)
        {
            curr -> next = curr -> next -> next;
            flag = 1;
        }
        else if (flag == 1)
        {
            prev -> next = curr -> next;
            curr = prev -> next;
            flag = 0;
        }
        else
        {
            prev = curr;
            curr = curr -> next;
        }
    }
    if (flag == 1)
        prev -> next = NULL;
    if (dummy -> next == NULL)
        cout << "Empty List";
    else
        printlist(dummy -> next);
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
    duplicates(root);
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