
/**
* @author : lengpi
* @date : 2020-12-06 14:31
**/

#include <bits/stdc++.h>

using namespace std;

/*
 * 解法一：
 * 动态规划：dp[i][j] 表示第 i 行以 j 结尾的最大连续为 1 的串长度
 * 遍历 i 到 0，取最小宽度乘以高度，然后取 max
 * 时间复杂度：O(N^2*M)
 * 空间复杂度：O(N*M)
 * */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int> > dp(n + 1);
        for(int i = 0; i < n; ++i) {
            dp[i].resize(m + 1);
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = (j == 0) ? 1 : dp[i][j - 1] + 1;
                    int width = dp[i][j];
                    for(int k = i; k >= 0; k--){
                        width = min(width, dp[k][j]);
                        ans = max(ans, width * (i - k + 1));
                    }
                }
            }
        }
        return ans;
    }
};
