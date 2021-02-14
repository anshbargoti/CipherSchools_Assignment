#include<bits/stdc++.h>
using namespace std;



//#define int long long
// const int MOD = 1000000007;



void striker()
{
    int x, v_x, y, v_y;
    cin >> x >> v_x >> y >> v_y;
    if ( (x > y && v_x >= v_y) || (x < y && v_x <= v_y) )
    {
        cout << "They will never meet";
        return;
    }
    if (x > y)
    {
        swap(x, y);
        swap(v_x, v_y);
    }
    if ( (y - x) % (v_x - v_y) == 0 )
        cout << "They will meet";
    else
        cout << "They will never meet";
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