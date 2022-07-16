/* Merge Intervals (https://leetcode.com/problems/merge-intervals/) */

#include<bits/stdc++.h>
using namespace std;

bool sortInterval(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0];
}

vector<vector<int>> Merge_interval(vector<vector<int>>& intervals)
{
    int n = intervals.size();

    sort(intervals.begin(),intervals.end(),sortInterval);

    vector<vector<int>> ans;

    vector<int> current = intervals[0];

    for(int i=1;i<n;i++)
    {
        vector<int> interval = intervals[i];
        if(current[1] >= interval[1])
        {
            current[1] = max(current[1], interval[1]);
        }
        else
        {
            ans.push_back(current);
            current = interval;
        }
    }
    ans.push_back(current);
    return ans;
}

int main()
{
    vector<vector<int>> intervals = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
    vector<vector<int>> ans = Merge_interval(intervals);

    cout << "\n The Merged Intervals are : ";
    for (int i = 0; i <= ans.size() ; i++)
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "] ";
    return 0;
}