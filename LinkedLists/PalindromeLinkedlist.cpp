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


bool checkPld(Node *head1, Node *head2)
{
    while (head2 != NULL)
    {
        if (head1 -> data != head2 -> data)
            return false;
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    return true;
}

struct Node *reversell(Node *curr, Node *prev)
{
    while (curr != NULL)
    {
        Node *next_val = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next_val;
    }
    return prev;
}

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

bool palindrome(Node *root)
{
    Node *slow = root;
    Node *fast = root;
    while (fast -> next != NULL && fast -> next -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    Node *rev_head = slow -> next;
    Node *new_rev_head = reversell(rev_head, NULL);
    slow -> next = new_rev_head;
    bool flag = checkPld(root, new_rev_head);
    Node *update_rev_head = reversell(new_rev_head, NULL);
    slow -> next = update_rev_head;
    return flag;
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
    cout << palindrome(root);
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