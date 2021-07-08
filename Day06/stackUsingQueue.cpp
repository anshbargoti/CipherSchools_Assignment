#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


class StackUsingQueue
{
    queue<int> q1, q2;
    int siz;
public:
    StackUsingQueue()
    {
        siz = 0;
    }

    void push(int x)
    {
        q2.push(x);
        siz++;
        while (!q1.empty())
        {
            int top = q1.front();
            q1.pop();
            q2.push(top);
        }

        swap(q1, q2);
    }

    int top()
    {
        if (!q1.empty())
            return q1.front();
        else
            return -1;
    }


    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
        siz--;
    }

    int size()
    {
        return siz;
    }

};


void striker()
{
    StackUsingQueue s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout << "Size : " << s.size() << endl;
    cout << "Top Element : " << s.top() << endl;
    s.pop();
    cout << "Top Element : " << s.top() << endl;
    cout << "Size : " << s.size() << endl;
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