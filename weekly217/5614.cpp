#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        stack<int> sta;
        sta.push(-1);
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            while(nums[i] < sta.top() && k - sta.size() + 1< n - i) {
                sta.pop();
            }
            if(sta.size() < k + 1) sta.push(nums[i]);
        }
        vector<int> res;
        while(k--) {
            res.push_back(sta.top());
            sta.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

main()
{
    return 0;
}