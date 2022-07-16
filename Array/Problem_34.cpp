/* Minimum no. of operations required to make an array palindrome
(https://practice.geeksforgeeks.org/problems/palindromic-array/0) */

#include<bits/stdc++.h>
using namespace std;

int min_operation(vector<int> arr)
{
    int n = arr.size();
    int i = 0 , j = n-1;
    int op = 0;
    while(i < j)
    {
        if(arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else if(arr[i] < arr[j])
        {
            arr[i+1] += arr[i];
            i++;
            op++;
        }
        else
        {
            arr[j-1] += arr[j];
            j--;
            op++;
        }
    }
    return op;
}

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter elements in arr : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Minimum no. of operations required to make an array palindrome : "<<min_operation(arr);

    return 0;
}