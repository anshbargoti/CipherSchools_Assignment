#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// #define int long long
// const int MOD = 1000000007;


struct mystack
{
	int *arr;
	int top, capc;
	mystack(int n)
	{
		capc = n;
		arr = new int[capc];
		top = -1;
	}

	void push(int x)
	{
		if (top >= capc - 1)
		{
			cout << "Stack Overflow" << "\n";
			return;
		}
		arr[++top] = x;
		cout << "Pushed " << x << "\n";
	}

	int pop()
	{
		if (top < 0)
		{
			cout << "Stack Underflow" << "\n";
			return INT_MIN;
		}
		return arr[top--];
	}

	int peek()
	{
		if (top < 0)
		{
			cout << "Stack Empty" << "\n";
			return INT_MIN;
		}
		return arr[top];
	}

	int size()
	{
		return (top + 1);
	}

	bool empty()
	{
		return (top < 0);
	}
};


void striker()
{
	mystack s(5);
	s.push(2);
	s.push(3);
	s.push(6);
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
	
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
    	// cout << "#Case: "<< i + 1 << endl;
    	striker();
    	// cout << endl;
    }
 	return 0;
}