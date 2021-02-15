#include<bits/stdc++.h>
using namespace std;



//#define int long long
// const int MOD = 1000000007;



int search_fun(int l, int r, int arr[], int key)
{
    if (l > r)
        return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[l] <= arr[mid])
    {
        if (key >= arr[l] && key <= arr[mid]) 
            return search_fun(l, mid - 1, arr, key); 
        return search_fun(mid + 1, r, arr, key); 
    }
    if (key >= arr[mid] && key <= arr[r]) 
        return search_fun(mid + 1, r, arr, key); 
    return search_fun(l, mid - 1, arr, key); 
}


void striker()
{
    int n, key;
    cin >> n >> key;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int indx = search_fun(0, n - 1, arr, key);
    if (indx == -1)
        cout << "Element not present";
    else
        cout << "Element present : " << indx;
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