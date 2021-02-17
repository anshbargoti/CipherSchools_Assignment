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


void makeloop(Node* head, Node* tail, int position)
{
    if (position == 0)
        return;
    Node* walk = head;
    for(int i = 1; i < position; i++)
        walk = walk -> next;
    tail -> next = walk;
}

void detectRemoval(Node *root)
{
    Node *slow = root;
    Node *fast = root;
    bool flag = false;
    while (fast -> next != NULL && fast -> next -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast)
        {
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "No Loop Present";
        return;
    }
    slow = root;
    if (slow == fast)
    {
        while(fast -> next != slow)
            fast = fast -> next;
    }
    else
    {while (slow -> next != fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
    fast -> next = NULL;
    cout << "Loop was Present" << endl;
    printlist(root);
}

void striker()
{
    int n, pos;
    cin >> n >> pos;
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
    makeloop(root, tail, pos);
    detectRemoval(root);
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