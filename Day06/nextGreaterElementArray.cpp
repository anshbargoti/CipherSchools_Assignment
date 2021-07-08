#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


void striker()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res[n];
    stack <int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty())
        {
            if (s.top() <= arr[i])
                s.pop();
            else
                break;
        }

        if (s.empty())
            res[i] = -1;
        else
            res[i] = s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
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