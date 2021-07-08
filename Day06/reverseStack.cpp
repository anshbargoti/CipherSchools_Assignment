#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


void striker()
{
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    queue <int> q;
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
        st.push(t);
    }

    while (!st.empty())
    {
        int t = st.top();
        st.pop();
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