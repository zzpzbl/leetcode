
/**
* @author : lengpi
* @date : 2020-12-03 16:23
**/

#include <bits/stdc++.h>
using namespace std;


/*
 单调栈
 */
int largestRectangleArea(vector<int>& heights) {
    stack<int> sta;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    int n = heights.size();
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(sta.empty() || heights[sta.top()] <= heights[i]) {
            sta.push(i);
        }
        else {
            while(!sta.empty() && heights[sta.top()] > heights[i]) {
                int cur = sta.top();
                sta.pop();
                int l = sta.top() + 1;
                int r = i - 1;
                ans = max(ans, (r - l + 1) * heights[cur]);
            }
            sta.push(i);
        }
    }
    return ans;
}

int main()
{
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << largestRectangleArea(v) << endl;
}