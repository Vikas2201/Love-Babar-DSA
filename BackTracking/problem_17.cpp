/* Print all possible paths from top left to bottom right of a mXn matrix
(https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-tobottom-right-of-a-mxn-matrix/) */

#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int M, int N) 
{
    return (i >= 0 && i < M && j >= 0 && j < N);
}
 
// Function to print the route taken
void printPath(vector<int> const &path, int last)
{
    for (int i: path) 
    {
        cout << i << ", ";
    }
    cout << last << endl;
}
 
void findPaths(vector<vector<int>>& mat, vector<int>& path, int i, int j)
{
    // base case
    if (mat.size() == 0) 
    {
        return;
    }
 
    // `M × N` matrix
    int M = mat.size();
    int N = mat[0].size();
 
    // if the last cell is reached, print the route
    if (i == M - 1 && j == N - 1)
    {
        printPath(path, mat[i][j]);
        return;
    }
 
    // include the current cell in the path
    path.push_back(mat[i][j]);
 
    // move right
    if (isValid(i, j + 1, M, N)) 
    {
        findPaths(mat, path, i, j + 1);
    }
 
    // move down
    if (isValid(i + 1, j, M, N)) 
    {
        findPaths(mat, path, i + 1, j);
    }
 
    // backtrack: remove the current cell from the path
    path.pop_back();
}
 
int main()
{
    vector<vector<int>> mat =
    {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
 
    vector<int> path;
    
    cout<<"All the possible path : ";
    findPaths(mat, path, 0, 0);
 
    return 0;
}
