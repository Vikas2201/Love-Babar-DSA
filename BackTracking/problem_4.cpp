/* Remove Invalid Parentheses (https://leetcode.com/problems/remove-invalidparentheses/) */

#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
unordered_map<string,int> mp;
int invalid_Parenteses(string s)
{
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '(')
            st.push(s[i]);
        else if(s[i] == ')')
        {
            if(st.size() > 0  && st.top() == '(')
                st.pop();
            else
                st.push(s[i]);
        }
    }
    return st.size();
}

void solve(string s,int c)
{
    if(mp[s] != 0)
        return ;
    else
        mp[s]++;
    if(c < 0)
        return ;
    if(c == 0)
    {
        if(invalid_Parenteses(s) == 0)
            ans.push_back(s);
        return ;
    }
    for(int i=0;i<s.size();i++)
    {
        string left = s.substr(0,i);
        string right = s.substr(i+1);
        solve(left+right , c-1);
    }
    return ;
}


int main()
{
    string s;
    cout<<"Enter Invalid Parenteses : ";
    cin>>s;

    solve(s,invalid_Parenteses(s));

    cout<<"Correct Parenteses : ";
    for(auto i : ans)
        cout<<i<<" ";

    return 0;
}