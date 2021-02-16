#include<bits/stdc++.h>
using namespace std;
#define N 4
int chessBoard[N][N];



//#define int long long
// const int MOD = 1000000007;

  
bool isSafe(int row, int col) 
{ 
  
    for (int i = 0; i < col; i++)
    {
        if (chessBoard[row][i] == 1) 
            return false; 
    }
  
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
    {
        if (chessBoard[i][j] == 1) 
            return false; 
    }
  
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (chessBoard[i][j] == 1) 
            return false; 
    }
    return true; 
} 
  
bool safeRec(int col) 
{ 
    if (col == N) 
        return true; 
  
    for (int i = 0; i < N; i++)
    { 
     
        if (isSafe(i, col))
        { 
            chessBoard[i][col] = 1; 
            if (safeRec(col + 1)) 
                return true;
            chessBoard[i][col] = 0;
        } 
    }  
    return false; 
} 
  
bool valid() 
{
    if (safeRec(0) == false) 
        return false; 
    return true; 
}

void striker()
{
    int n;
    cin >> n;
    bool flag = valid();
    if (flag)
    {
        for (int i = 0; i < N; i++)
        { 
            for (int j = 0; j < N; j++)
            {
                cout << chessBoard[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "Solution not exist";
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
        // cout << "#Case: " << i + 1 << endl;
        striker();
        // cout << endl;
    }
    return 0;
}