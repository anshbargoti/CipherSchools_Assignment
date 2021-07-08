#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


void striker()
{
    string str = "((a+(b))+(c+d))";
    stack <char> stk;
    for (auto x : str)
    {
        if (x != ')')
            stk.push(x);
        else
        {
            char top = stk.top();
            stk.pop();
            int count_in = 0;
            while (top != '(')
            {
                count_in++;
                top = stk.top();
                stk.pop();
            }
            if (count_in == 0)
            {
                cout << "Duplicate Parenthesis Exist";
                return;
            }
        }
    }
    cout << "Duplicate Parenthesis not exist";
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