#include<bits/stdc++.h>
using namespace std;
const int no_of_chars = 256;


//#define int long long
// const int MOD = 1000000007;



void striker()
{
    string txt, pttr;
    getline(cin, txt);
    getline(cin, pttr);
    int n1 = txt.length();
    int n2 = pttr.length();
 
    if (n1 < n2)
    {
        cout << "No such window exists";
        return;
    }
 
    int hash_pat[no_of_chars] = { 0 };
    int hash_str[no_of_chars] = { 0 };

    for (int i = 0; i < n2; i++)
        hash_pat[pttr[i]]++;
 
    int start = 0, start_index = -1, min_len = INT_MAX;
    int count = 0; 
    for (int j = 0; j < n1; j++) 
    {
        hash_str[txt[j]]++;
        if (hash_str[txt[j]] <= hash_pat[txt[j]])
            count++;
        if (count == n2)
        {
           
            while (hash_str[txt[start]] > hash_pat[txt[start]] || hash_pat[txt[start]] == 0)
            {
 
                if (hash_str[txt[start]] > hash_pat[txt[start]])
                    hash_str[txt[start]]--;
                start++;
            }
 
            int len_window = j - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
    }
    if (start_index == -1)
    {
        cout << "No such window exists";
        return;
    }
    cout << txt.substr(start_index, min_len);
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