/* Print all permutations of a string
(https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0) */

#include<bits/stdc++.h>
using namespace std;

void permutation(string s,int pos,set<string>& ans)
{
    if(pos == s.size())
    {
        ans.insert(s);
        return ;
    }
    for(int i=pos;i<s.size();i++)
    {
        swap(s[i],s[pos]);
        permutation(s,pos+1,ans);
        swap(s[i],s[pos]);
    }
    return ;
}

int main()
{
    string s;
    cout<<"Enter string : ";
    cin>>s;

    set<string> ans;
    permutation(s,0,ans);
    cout<<"All possible permutation : ";
    for(auto i : ans)
        cout<<i<<" ";
    
    return 0;
}