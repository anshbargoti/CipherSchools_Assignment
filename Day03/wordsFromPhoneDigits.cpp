#include<bits/stdc++.h>
using namespace std;


void printWords(vector<string> v, int curr, string s)
{
    if(curr == v.size()){
        cout<<s<<" ";
        return;
    }
    string st = v[curr];
    for(int i=0; i<st.size(); i++)
        printWords(v, curr+1, s + st[i]);
}


void possibleWords(int arr[], int n)
{
    string words[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> v;
    for(int i = 0; i < n; i++){
        v.push_back(words[arr[i]]);
    }

    printWords(v, 0, "");
}


void striker()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    possibleWords(arr, n);
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
        // cout << "#Case: " << i + 1 << endl;
        striker();
        cout << endl;
    }
    return 0;
}