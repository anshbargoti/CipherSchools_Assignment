#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


class QueueUsingStack
{
    stack<int> s1, s2;
    int siz;
public:
    QueueUsingStack()
    {
        siz = 0;
    }

    void enqueue(int x)
    {
        while (!s1.empty())
        {
            int tp = s1.top();
            s1.pop();
            s2.push(tp);
        }

        s1.push(x);

        while (!s2.empty())
        {
            int tp = s2.top();
            s2.pop();
            s1.push(tp);
        }

        siz++;
    }

    int front()
    {
        if (!s1.empty())
            return s1.top();
        else
            return -1;
    }


    void dequeue()
    {
        if (s1.empty())
            return;
        s1.pop();
        siz--;
    }

    int size()
    {
        return siz;
    }
    
};



void striker()
{
    QueueUsingStack q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    cout << "Size : " << q.size() << endl;
    cout << "Front Element : " << q.front() << endl;
    q.dequeue();
    cout << "Front Element : " << q.front() << endl;
    cout << "Size : " << q.size() << endl;
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