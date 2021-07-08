#include<bits/stdc++.h>
using namespace std;


struct Node 
{
    int data;
    Node *next, *prev;
    Node (int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


class Doublell
{
    public:
        Node *head, *tail;

        Doublell()
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
            }
            else
            {
                tail -> next = new Node(x);
                tail -> next -> prev = tail;
                tail = tail -> next;
            }
        }
        
        
        void traverse()
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
            cout << endl;
        }


        void remove(int x)
        {
            if (head == NULL)
                return;
            if (head -> data == x)
            {
                Node *temp = head;
                head = head -> next;
                temp -> next = NULL;
                head -> prev = NULL;
                return;
            }
            Node *temp = head -> next;
            while (temp != NULL)
            {
                if (temp -> data == x)
                {
                    if (temp == tail)
                        tail = temp -> prev;
                    temp -> prev -> next = temp -> next;
                    if (temp -> next != NULL)
                        temp -> next -> prev = temp -> prev;
                }
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
    Doublell list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.traverse();
    list.remove(2);
    list.traverse();
    list.update(4, 10);
    list.traverse();
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