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



Node *reversell(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next_val = NULL;
    while (curr != NULL)
    {
        next_val = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next_val;
    }
    return prev;
}


Node *reorder(Node *root)
{
    Node *slow = root;
    Node *fast = root;
    while (fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    Node *root1 = root;
    Node *root2 = slow -> next;
    cout << root1 -> data << " " << root2 -> data << endl;
    slow -> next = NULL;
    root2 = reversell(root2);
    Node *new_head = new Node(0);
    Node *curr = new_head;
    while (root1 != NULL || root2 != NULL)
    {
        if (root1 != NULL)
        {
            curr -> next = root1;
            root1 = root1 -> next;
            curr = curr -> next;
        }
        if (root2 != NULL)
        {
            curr -> next = root2;
            root2 = root2 -> next;
            curr = curr -> next;
        }
    }
    return (new_head -> next);
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
    Node *head = reorder(root);
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