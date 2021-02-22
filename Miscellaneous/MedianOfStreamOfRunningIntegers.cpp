#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// #define int long long
// const int MOD = 1000000007;



void median(int arr[], int n)
{
    priority_queue<int> p;
    priority_queue<int, vector<int>,greater<int>> q;
    p.push(arr[0]);
    cout << arr[0] << " ";
    for(int i = 1; i < n; i++)
    {
        int x = arr[i];
        if (p.size() > q.size())
        {
            if (p.top() > x)
            {
                q.push(p.top());
                p.pop();
                p.push(x);
            }
            else
                q.push(x);

            cout << (p.top() + q.top()) / 2.0 << " ";
        }
        else
        {
            if(x <= p.top())
                p.push(x);
            else
            {
                q.push(x);
                p.push(q.top());
                q.pop();
            }
            
            cout << p.top() << " ";
        }
    }
}


void striker()
{
    int arr[] = {12, 15, 10, 5, 8, 7, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    median(arr, n);
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