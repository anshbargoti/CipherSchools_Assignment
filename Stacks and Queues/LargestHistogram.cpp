#include<bits/stdc++.h>
using namespace std;
#define endl "\n"



// #define int long long
// const int MOD = 1000000007;




void striker()
{
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    stack <int> s;
    int res = 0;
    int tmp;
    int curr;
    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && arr[s.top()] >= arr[i])
        {
            tmp = s.top();
            s.pop();
            curr = arr[tmp] * (s.empty() ? i : i - s.top() - 1);
            res = max(res, curr);
        }
        s.push(i);
    }
    while(!s.empty())
    {
        tmp = s.top();
        s.pop();
        curr = arr[tmp] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }
    
    cout << res;

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