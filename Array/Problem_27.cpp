/* Maximum profit by buying and selling a share atmost twice
(https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-ashare-at-most-twice/) */

#include<bits/stdc++.h>
using namespace std;

int maximum_profit(vector<int> arr)
{
    int n = arr.size();
    int first_sell = 0,first_buy = INT_MIN , second_sell = 0 , second_buy = INT_MIN;
    for(int i=0;i<n;i++)
    {
        first_buy = max(first_buy,-arr[i]);//we set prices to negative, so the calculation of profit will be convenient
        first_sell = max(first_sell,first_buy+arr[i]);
        second_buy = max(second_buy,first_sell-arr[i]);//we can buy the second only after first is sold
        second_sell = max(second_sell,second_buy+arr[i]);
    }
    return second_sell;
}

int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter price in arr : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Maximum profit : "<<maximum_profit(arr);

    return 0;
}