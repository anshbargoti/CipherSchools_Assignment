#include<bits/stdc++.h>
using namespace std;
#define endl "\n"



// #define int long long
// const int MOD = 1000000007;






void striker()
{
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    stack <int> st;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        st.push(t);
    }
    while (!st.empty())
    {
        int t = st.top();
        st.pop();
        q.push(t);
    }

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        cout << t << " ";
    }
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