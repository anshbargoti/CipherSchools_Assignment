#include<bits/stdc++.h>
using namespace std;
#define endl "\n"



// #define int long long
// const int MOD = 1000000007;




stack <int> sort(stack<int> &stk) 
{ 
    stack<int> tempr; 
  
    while (!stk.empty()) 
    {
        int tmp = stk.top(); 
        stk.pop(); 
        while (!tempr.empty() && tempr.top() > tmp) 
        { 
            stk.push(tempr.top()); 
            tempr.pop(); 
        }
        tempr.push(tmp); 
    } 
  
    return tempr; 
} 



void striker()
{
    stack <int> s;
    s.push(1);
    s.push(20);
    s.push(5);
    s.push(2);
    s.push(30);
    s.push(4);
    stack <int> st = sort(s);
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