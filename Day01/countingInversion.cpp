#include<bits/stdc++.h>
using namespace std;


int mergePart(int arr[], int brr[], int left, int mid, int right)
{
    int l = left, m = mid, r = left, count = 0;
    while ( (l <= mid - 1) && (m <= right) )
    {
        if (arr[l] <= arr[m])
            brr[r++] = arr[l++];
        else
        {
            brr[r++] = arr[m++];
            count = count + (mid - l);
        }
    }
    while (l <= mid - 1)
        brr[r++] = arr[l++];
    while (m <= right)
        brr[r++] = arr[m++];
    for (l = left; l <= right; l++)
        arr[l] = brr[l];
    return count;
}


int divConq(int arr[], int brr[], int l, int r)
{
    int count = 0;
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        count += divConq(arr, brr, l, mid);
        count += divConq(arr, brr, mid + 1, r);
        count += mergePart(arr, brr, l, mid + 1, r);
    }
    return count;
}


void striker()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int brr[n];
    cout << "Total Inversions : " << divConq(arr, brr, 0, n - 1);
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