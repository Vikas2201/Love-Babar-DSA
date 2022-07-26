/* Sudoku Solver (https://practice.geeksforgeeks.org/problems/solve-the-sudoku/0) */

#include<bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<char>> board,int r,int c,char val)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][c] == val)
            return false;
    
        if(board[r][i] == val)
            return false;
            
        if(board[3* (r/3) + i/3][3* (c/3) + i%3] == val)
            return false;
    }
    return true;
}
    
bool solve(vector<vector<char>>& board)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j] == '.')
            {
                for(char c = '1';c <= '9';c++)
                {
                    if(issafe(board,i,j,c))
                    {
                        board[i][j] = c;
                    
                        if(solve(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board;
    board = {{"5" "3" "." "." "7" "." "." "." "."},
            {"6" "." "." "1" "9" "5" "." "." "."},
            {"." "9" "8" "." "." "." "." "6" "."},
            {"8" "." "." "." "6" "." "." "." "3"},
            {"4" "." "." "8" "." "3" "." "." "1"},
            {"7" "." "." "." "2" "." "." "." "6"},
            {"." "6" "." "." "." "." "2" "8" "."},
            {"." "." "." "4" "1" "9" "." "." "5"},
            {"." "." "." "." "8" "." "." "7" "9"}};
    
    if(solve(board))
    {
        cout<<"Complete sudoku : ";
        for(auto b : board)
        {
            for(auto i : b)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}