#include<bits/stdc++.h>
using namespace std;


int findCand(int arr[], int n)
{
    int ind = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[ind])
            count++;
        else
            count--;
        if (count == 0)
        {
            count = 1;
            ind = i;
        }
    }
    return arr[ind];
}

void striker()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int val = findCand(arr, n);
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == val)
            count++;
    if (count > n / 2)
        cout << "Majority Element : " << val;
    else
        cout << "No Majority Element";
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