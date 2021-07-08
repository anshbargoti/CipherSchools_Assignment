#include<bits/stdc++.h>
using namespace std;


struct Node 
{
    int data;
    Node *next, *random;
    Node (int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};


void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << "Data : " << curr -> data;
        cout << "  ";
        cout << "Random : " << curr -> random -> data;
        curr = curr -> next;
        cout << endl;
    }
}


Node *clonell(Node *head)
{
    Node *curr = head;
    Node *temp = NULL;
    while (curr != NULL)
    {
        temp = curr -> next;
        curr -> next = new Node(curr -> data);
        curr -> next -> next = temp;
        curr = temp;
    }

    curr = head;
    temp = head;

    while (curr != NULL)
    {
        if (curr -> next != NULL)
            curr -> next -> random = (curr -> random ? curr -> random -> next : curr -> random);

        curr = (curr -> next ? curr -> next -> next : curr -> next); 
    }

    temp = curr = head -> next;
    while (curr != NULL && curr -> next != NULL)
    {
        curr -> next = curr -> next -> next;
        curr = curr -> next;
    }
    return temp;
}


void striker()
{
    Node *head = new Node(5);
    head -> next = new Node(10);
    head -> next -> next = new Node(15);
    head -> next -> next -> next = new Node(20);
    head -> next -> next -> next -> next = new Node(25);

    // 1's random points to 3
    head -> random = head -> next -> next;

    // 2's random points to 1 
    head -> next -> random = head; 
  
    // 3's and 4's random points to 5 
    head -> next -> next -> random = head -> next -> next -> next -> next; 
    head -> next -> next -> next -> random = head -> next -> next -> next -> next; 
  
    // 5's random points to 2 
    head -> next -> next -> next -> next -> random = head -> next;

    cout << "Original Linked list : " << endl;
    printlist(head);
    cout << "Cloned Linked list : " << endl;
    Node *root = clonell(head);
    printlist(root);
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