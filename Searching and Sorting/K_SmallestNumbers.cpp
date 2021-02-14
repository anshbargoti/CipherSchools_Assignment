#include<bits/stdc++.h>
using namespace std;



//#define int long long
// const int MOD = 1000000007;


int partn(int l, int h, int arr[])
{
    int low = l;
    for (int i = l; i < h; i++)
    {
        if (arr[h] >= arr[i])
        {
            swap(arr[low], arr[i]);
            low++;
        }
    }
    swap(arr[low], arr[h]);
    return low;
}


int randPart(int l, int h, int arr[])
{
    int pivot_ele = rand() % (h - l + 1);
    swap(arr[l + pivot_ele], arr[h]);
    return partn(l, h, arr);
}


int smallest(int l, int h, int arr[], int k)
{
    if (k <= h - l + 1 && k > 0)
    {
        int position = randPart(l, h, arr);
        if (position - l > k - 1)
            return smallest(l, position - 1, arr, k);
        else if (position - l == k - 1)
            return arr[position];
        return smallest(position + 1, h, arr, l - 1 + k - position);
    }
    return -1;
}


void striker()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Kth smallest element : " << smallest(0, n - 1, arr, k);
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