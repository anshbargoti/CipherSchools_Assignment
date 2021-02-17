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

int getNode(int count, Node *head1, Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;
    for (int i = 0; i < count; i++)
    {
        if (curr1 != NULL)
            curr1 = curr1 -> next;
        else
            return -1;
    }
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1 == curr2)
            return (curr1 -> data);
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
    return -1;
}

findIntersection(Node *head1, Node *head2)
{
    int count1 = 0, count2 = 0;
    Node *curr = head1;
    while (curr != NULL)
    {
        count1++;
        curr = curr -> next;
    }
    curr = head2;
    while (curr != NULL)
    {
        count2++;
        curr = curr -> next;
    }
    if (count1 > count2)
        cout << getNode(count1 - count2, head1, head2);
    else
        cout << getNode(count2 - count1, head2, head1);
}


void striker()
{
    int n, m, comm;
    cin >> n >> m >> comm;
    Node *root1 = NULL, *root2 = NULL, *common = NULL, *tail = NULL;
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
    cin >> firstval;
    common = new Node(firstval);
    tail = common;
    for (int i = 1; i < comm; i++)
    {
        int x;
        cin >> x;
        tail -> next = new Node(x);
        tail = tail -> next;
    }
    Node *temp = root1;
    while (temp -> next != NULL)
        temp = temp -> next;
    temp -> next = common;
    temp = root2;
    while (temp -> next != NULL)
        temp = temp -> next;
    temp -> next = common;
    findIntersection(root1, root2);
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