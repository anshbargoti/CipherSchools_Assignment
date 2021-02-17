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



void addll(Node *root1, Node *root2)
{
    Node *curr1 = root1;
    Node *curr2 = root2;
    Node *head = NULL;
    int sum = curr1 -> data + curr2 -> data;
    int carry = 0;
    curr1 = curr1 -> next;
    curr2 = curr2 -> next;
    if (sum < 10)
        head = new Node(sum);
    else
    {
        head = new Node(sum % 10);
        carry = sum / 10;
    }
    Node *tail = head;
    while (curr1 != NULL || curr2 != NULL)
    {
        if (curr1 != NULL && curr2 != NULL)
            sum = curr1 -> data + curr2 -> data + carry;
        else if (curr1 != NULL)
            sum = curr1 -> data + 0 + carry;
        else
            sum = 0 + curr2 -> data + carry;
        carry = 0;
        if (sum < 10)
            tail -> next = new Node(sum);
        else
        {
            tail -> next = new Node(sum % 10);
            carry = sum / 10;
        }
        tail = tail -> next;
        if (curr1 != NULL)
            curr1 = curr1 -> next;
        if (curr2 != NULL)
            curr2 = curr2 -> next;
    }
    if (carry != 0)
        tail -> next = new Node(carry);
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
    addll(root1, root2);
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