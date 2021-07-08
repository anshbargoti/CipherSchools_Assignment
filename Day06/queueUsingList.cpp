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


struct myqueue
{
	Node *front, *rear;
	int siz;

	myqueue()
	{
		front = NULL;
		rear = NULL;
		siz = 0;
	}

	void qenqueue(int x)
	{
		Node *curr = new Node(x);
		cout << "Pushed " << x << endl;
		siz++;
		if (rear == NULL)
		{
			front = curr;
			rear = curr;
			return;
		}
		rear -> next = curr;
		rear = curr;
	}

	int qdequeue()
	{
		if (front == NULL)
		{
			cout << "Queue Empty" << endl;
			return INT_MIN;
		}
		int ans = front -> data;
		Node *temp = front;
		front = front -> next;
		delete(temp);
		siz--;
		return ans;
	}

	int qfront()
	{
		if (front == NULL)
		{
			cout << "Queue Empty" << endl;
			return INT_MIN;
		}
		return (front -> data);
	}

	int qrear()
	{
		if (rear == NULL)
		{
			cout << "Queue Empty" << endl;
			return INT_MIN;
		}
		return (rear -> data);
	}


	int qsiz()
	{
		return siz;
	}

	bool qempty()
	{
		return (front == NULL);
	}

};

void striker()
{
	myqueue q;
	q.qenqueue(1);
	q.qenqueue(2);
	q.qenqueue(3);
	q.qenqueue(4);
	cout << "Removed element : " << q.qdequeue() << endl;
	cout << "Removed element : " << q.qdequeue() << endl;
	cout << "Front element : " << q.qfront() << endl;
	cout << "Last element : " << q.qrear() << endl;
	cout << "Size : " << q.qsiz() << endl;
	cout << "Check Empty : " << q.qempty() << endl;
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