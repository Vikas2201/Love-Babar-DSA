/* Best time to buy and Sell stock (https://leetcode.com/problems/best-time-to-buyand-sell-stock/) */

#include<bits/stdc++.h>
using namespace std;

int max_profit(vector<int> profits)
{
    int n = profits.size();
    if(n == 1)
        return 0;
    int min_value = INT_MAX , profit = 0;
    for(int i=0;i<n;i++)
    {
        min_value = min(min_value,profits[i]);
        profit = max(profit,profits[i]-min_value);
    }
    return profit;
}

int main()
{
    int n;
    cout<<"Enter no. of days : ";
    cin>>n;

    vector<int> profits(n);
    cout<<"Enter profit of each day : ";
    for(int i=0;i<n;i++)
    {
        cin>>profits[i];
    }

    int profit = max_profit(profits);
    cout<<"maximum profit acceived : "<<profit;
    
    return 0;
}