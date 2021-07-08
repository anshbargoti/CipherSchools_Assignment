#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


struct Node
{
	int data;
	Node *next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};


struct  mystack
{
	Node *head;
	int siz;

	mystack()
	{
		head = NULL;
		siz = 0;
	}

	void push(int x)
	{
		Node *curr = new Node(x);
		curr -> next = head;
		head = curr;
		siz++;
		cout << "Pushed " << x << endl;
	}

	int pop()
	{
		if (head == NULL)
		{
			cout << "Stack Underflow" << endl;
			return INT_MIN;
		}
		int ans = head -> data;
		Node *temp = head;
		head = head -> next;
		delete(temp);
		siz--;
		return ans;
	}

	int peek()
	{
		if (head == NULL)
		{
			cout << "Stack Empty" << endl;
			return INT_MIN;
		}
		return (head -> data);
	}

	int size()
	{
		return siz;
	}

	bool empty()
	{
		return (head == NULL);
	}
};


void striker()
{
	mystack s;
	s.push(5);
	s.push(10);
	s.push(20);
	cout << "Pop element : " << s.pop() << endl;
	cout << "Pop element : " << s.pop() << endl;
	cout << "Top element : " << s.peek() << endl;
	cout << "Size : " << s.size() << endl;
	cout << "Check Empty : " << s.empty() << endl;
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
    	// cout << "#Case: "<< i + 1 << endl;
    	striker();
    	cout << endl;
    }
 	return 0;
}