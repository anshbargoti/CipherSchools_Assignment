#include<bits/stdc++.h>
using namespace std;


void striker()
{
    char board[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
    bool flag = true;  
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int num = board[i][j] - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (used1[i][num] || used2[j][num] || used3[k][num])
                {
                    flag = false;
                    break;
                }
                used1[i][num] = used2[j][num] = used3[k][num] = 1;
            }
        }
    }
    cout << (flag ? "Sudoku Valid" : "Sudoku Not Valid");
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