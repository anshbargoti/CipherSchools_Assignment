#include<bits/stdc++.h>
using namespace std;


//#define int long long
// const int MOD = 1000000007;



int binrSearch(int l, int r, int x, int arr[])
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binrSearch(l, mid - 1, x, arr); 
        return binrSearch(mid + 1, r, x, arr); 
    }
    return -1; 
}


void striker()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ind = binrSearch(0, n - 1, x, arr);
    if (ind != -1)
        cout << "Element present at : " <<  ind;
    else
        cout << "Element not present";
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; i++)
    {
        //cout<<"#Case: "<<i+1<<endl;
        striker();
        // cout << endl;
    }
    return 0;
}