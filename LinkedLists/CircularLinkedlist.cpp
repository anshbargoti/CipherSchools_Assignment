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
    Node (int x, Node *nxt)
    {
        data = x;
        this -> next = nxt;
    }
};


class Circularll
{
    public:
        Node *head, *tail;

        Circularll()
        {
            this -> head = NULL;
            this -> tail = NULL;
        }

        void add(int x)
        {
            if (head == NULL)
            {
                head = new Node(x);
                tail = head;
                head -> next = head;
            }
            else
            {
                tail -> next = new Node(x, head);
                tail = tail -> next;
            }
        }
        
        
        void traverse()
        {
            if (head == NULL)
                return;
            Node *curr = head;
            do {
                cout << curr -> data << " ";
                curr = curr -> next;
            }
            while(curr != head);
            cout << endl;
        }


        void remove(int x)
        {
            if (head == NULL)
                return;
            if (head -> data == x)
            {
                if (head == tail)
                    head = tail = NULL;
                else
                {
                    head = head -> next;
                    tail -> next = head;
                }
                return;
            }
            Node *temp = head -> next, *prev = head;
            while (temp != NULL)
            {
                if (temp -> data == x)
                {
                    if (temp == tail)
                        tail = prev;
                    prev -> next = temp -> next;
                    return;
                }
                prev = temp;
                temp = temp -> next;
            }
        }

        void update(int x, int new_val)
        {
            Node *temp = head;
            while (temp != NULL)
            {
                if (temp -> data == x)
                {
                    temp -> data = new_val;
                    return;
                }
                temp = temp -> next;
            }
        }

};



void striker()
{
    Circularll list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.traverse();
    list.remove(3);
    list.traverse();
    list.update(1, 10);
    list.traverse();
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