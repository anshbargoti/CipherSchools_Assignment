#include<bits/stdc++.h>
using namespace std;


int firstOccur(int l, int h, int arr[], int x, int n)
{
    int res = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] < x)
            l = mid + 1;
        else if (arr[mid] >= x)
        {
            res = mid;
            h = mid - 1;
        }
    }
    return res;
}


int lastOccur(int l, int h, int arr[], int x, int n)
{
    int res = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] <= x)
        {
            res = mid;
            l = mid + 1;
        }
        else if (arr[mid] >= x)
            h = mid - 1;
    }
    return res;
}

void striker()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "First Occurence : " << firstOccur(0, n - 1, arr, x, n);
    cout << endl;
    cout << "Last Occurence : " << lastOccur(0, n - 1, arr, x, n);
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
        //cout<<"#Case: "<<i+1<<endl;
        striker();
        cout << endl;
    }
    return 0;
}