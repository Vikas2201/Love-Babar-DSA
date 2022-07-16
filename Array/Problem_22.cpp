/* Find factorial of a large number
(https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0) */

#include<bits/stdc++.h>
using namespace std;

vector<int> fact(int n)
{
    long long int ans = 1;
    for(int i = 2;i<= n;i++)
    {
        ans *= i;
    }
    vector<int> digit;
    while (ans > 0)
    {
        int r = ans%10;
        ans = ans/10;
        digit.push_back(r);
    }

    reverse(digit.begin(),digit.end());
    return digit;
}

int main()
{
    int n;
    cout<<"Enter number : ";
    cin>>n;

    cout<<"Digit of factorial of that number "<<n<<" : ";
    vector<int> digit = fact(n);

    for(auto i : digit)
    {
        cout<<i<<" ";
    }
    return 0;
}