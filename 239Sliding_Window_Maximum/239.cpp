
/**
* @author : lengpi
* @date : 2020-12-06 16:51
**/

/*
 * 双端队列
 * 自行百度概念
 * 维护一个非递增的单调队列，每次输出队列头即可
 * */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<pair<int, int> > dq;
        for(int i = 0; i < n; ++i) {
            while(!dq.empty() && i - dq.front().first > k - 1) dq.pop_front();
            while(!dq.empty() && dq.back().second < nums[i]) dq.pop_back();
            dq.push_back(make_pair(i, nums[i]));
            if(i < k - 1) continue;
            ans.push_back(dq.front().second);
        }
        return ans;
    }
};
