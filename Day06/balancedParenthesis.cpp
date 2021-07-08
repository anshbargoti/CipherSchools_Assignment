#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


void striker()
{
    string s = "{[()]()}";
    stack <char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stk.push(s[i]);
        else
        {
            if (stk.empty())
            {
                cout << "Not Balanced" << endl;
                return;
            }
            char peek = stk.top();
            if ( (s[i] == ')' && peek == '(') || (s[i] == ']' && peek == '[') || (s[i] == '}' && peek == '{') )
                stk.pop();
            else
            {
                cout << "Not Balanced" << endl;
                return;
            }
        }
    }
    if (stk.size() == 0)
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
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