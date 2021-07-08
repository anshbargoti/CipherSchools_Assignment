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


void reversell(Node *root, int k)
{
    stack<Node *> stk;
    Node *curr = root, *prev = NULL;
    int count_k = 0;
    while (curr != NULL)
    {
        count_k = 0;
        while (count_k < k && curr != NULL)
        {
            stk.push(curr);
            count_k++;
            curr = curr -> next;
        }

        while (stk.size() != 0)
        {
            if (prev == NULL)
            {
                prev = stk.top();
                stk.pop();
                root = prev;
            }
            else
            {
                Node *temp = stk.top();
                stk.pop();
                prev -> next = temp;
                prev = prev -> next;
            }
        }
    }
    prev -> next = NULL;
    printlist(root);
}


void striker()
{
    int n, k;
    cin >> n >> k;
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
    reversell(root, k);
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