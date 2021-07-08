#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


void striker()
{
    int arr[] = {1, 6, 4, 10, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty())
        {
            if (stk.top() < arr[i])
                break;
            else
                stk.pop();
        }
        if (stk.empty())
            cout << "-" << " ";
        else
            cout << stk.top() << " ";
        stk.push(arr[i]);
    }
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