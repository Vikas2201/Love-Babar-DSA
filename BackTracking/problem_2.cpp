/* Printing all solutions in N-Queen Problem (https://www.geeksforgeeks.org/printingsolutions-n-queen-problem/) */

#include<bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<int>>& board,int r,int c)
{
    for(int i=0;i<r;i++)  /* for check column */
        if(board[i][c] == 1)
            return false;
    
    for(int i=r , j =c;i >= 0,j >= 0;i--,j--)  /* left diagonal */
        if(board[i][j] == 1)
            return false;
    
    for(int i=r,j = c;i >= 0,j < board.size();i--,j++) /* right diagonal */ 
        if(board[i][j] == 1)
            return false;
    
    return true;
}

bool place_queen(vector<vector<int>>& board,int row)
{
    if(row >= board.size())
        return true;
    
    for(int i=0;i<board.size();i++)
    {
        if(issafe(board,row,i))
        {
            board[row][i] = 1;
            if(place_queen(board,row+1))
                return true;
        }
        board[row][i] = 0;
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter size of board : ";
    cin>>n;

    vector<vector<int>> board(n, vector<int> (n,0));
    if(place_queen(board,0))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 1)
                {
                    cout<<j<<" ";
                }
            }
        }
    }
    else
        cout<<"Does not exist";
    return 0;
}