#include<bits/stdc++.h>
using namespace std;


void striker()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int low = 0, high = n - 1;
    int ind = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
        {
            ind = mid;
            break;
        }
        else if (arr[mid - 1] > arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << "Index of peak element : " << ind;
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