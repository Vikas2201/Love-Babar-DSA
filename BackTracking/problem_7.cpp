/* Print all palindromic partitions of a string (https://www.geeksforgeeks.org/given-astring-print-all-possible-palindromic-partition/)*/

#include<bits/stdc++.h>
using namespace std;

bool check(string s,int start,int end)
{
    while(start < end)
    {
        if(s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void all_palindromic(string s,int start,vector<string>& ans,vector<vector<string>>& output)
{
    if(start >= s.size())
    {
        output.push_back(ans);
        return;
    }
    
    for(int i=start;i<s.size();i++)
    {
        if(check(s,start,i) == true)
        {
            ans.push_back(s.substr(start,i-start+1));

            all_palindromic(s,i+1,ans,output);

            ans.pop_back();
        }
    }
    return ;
}

int main()
{
    string s;
    cout<<"Enter string : ";
    cin>>s;

    vector<vector<string>> output;
    vector<string> ans;
    all_palindromic(s,0,ans,output);

    cout<<"All partitions generated by above call : ";
    for (int i=0; i< output.size(); i++ )
    {
        for (int j=0; j<output[i].size(); j++)
            cout << output[i][j] <<" ";
        cout << "\n";
    }
    return 0;
}