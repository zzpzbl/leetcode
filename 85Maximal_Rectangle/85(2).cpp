
/**
* @author : lengpi
* @date : 2020-12-06 14:34
**/


/*
 * 单调栈
 * 结合 84 理解
 * */
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        vector<int> tmp = heights;
        stack<int> sta;
        tmp.insert(tmp.begin(), 0);
        tmp.push_back(0);
        int n = tmp.size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(sta.empty() || tmp[sta.top()] <= tmp[i]) {
                sta.push(i);
            }
            else {
                while(!sta.empty() && tmp[sta.top()] > tmp[i]) {
                    int cur = sta.top();
                    sta.pop();
                    int l = sta.top() + 1;
                    int r = i - 1;
                    ans = max(ans, (r - l + 1) * tmp[cur]);
                }
                sta.push(i);
            }
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        int ans = 0;
        vector<int> dp(m + 1, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                dp[j] = (matrix[i][j] == '1') ? (dp[j] + 1) : 0;
            }
            ans = max(ans, largestRectangleArea(dp));
        }
        return ans;
    }
};
