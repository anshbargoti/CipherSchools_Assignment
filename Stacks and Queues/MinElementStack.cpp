#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// #define int long long
// const int MOD = 1000000007;



struct mystack
{
	stack<int> st;
	int mini;

	void push(int x)
 	{
        if(st.empty())
        {
        	mini = x;
        	st.push(x);
        	cout << "Pushed " << x << endl;
        	return;
        }
        if (x >= mini)
        	st.push(x);
        else
        {
        	st.push(2 * x - mini);
        	mini = x;
        }
        cout << "Pushed " << x << endl;
    }
 
    void pop()
    {
    	if (st.empty())
    	{
    		cout << "Stack empty" << endl;
    		return;
    	}
    	if (mini <= st.top())
    	{
    		cout << "Removed element " << st.top() << endl;
    		st.pop();
    	}
    	else
    	{
    		cout << "Removed element " << mini << endl;
    		mini = 2 * mini - st.top();
    		st.pop();
    	}
    }

    void peek()
    {
    	if (st.empty())
    	{
    		cout << "Stack empty" << endl;
    		return;
    	}
    	if (st.top() >= mini)
    		cout << "Top element " << st.top() << endl;
    	else
    		cout << "Top element " << mini << endl;
    }

   	void getMin()
   	{
   		if (st.empty())
   			cout << "Stack empty" << endl;
   		else
   			cout << "Minimum element so far " << mini << endl;
   	}

};



void striker()
{
	mystack s;
	s.push(5);
	s.push(10);
	s.getMin();
	s.push(3);
	cout << "mini " << s.mini << endl;
	s.peek();
	cout << "mini " << s.mini << endl;
	s.push(2);
	s.getMin();
	s.pop();
	cout << "mini " << s.mini << endl;
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