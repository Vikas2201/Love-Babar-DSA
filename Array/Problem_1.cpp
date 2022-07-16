/* Reverse the array (https://www.geeksforgeeks.org/write-a-program-to-reversean-array-or-string/) */
#include<bits/stdc++.h>
using namespace std;

vector<int> Reverse(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    return arr;
}

int main()
{
    int n;
    cout<<"Enter size of arr : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter element in arr : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Reverse of arr : ";
    arr = Reverse(arr);
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    return 0;
}