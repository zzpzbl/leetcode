#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int dif[4 + 2 * limit];
        for(int i = 0; i < 2 + 2 * limit; ++i) dif[i] = 2;
        int n = nums.size();

        for(int i = 0; i < n / 2; ++i) {
            int a = nums[i], b = nums[n - i - 1];
            if(a > b) swap(a, b);
            dif[a + 1]--;
            dif[a + b]--;
            dif[a + b + 1]++;
            dif[b + limit + 1]++;
        }

        int now_ans = 0;
        int ans = n;
        for(int i = 2; i <= limit * 2; ++i) {
            now_ans += dif[i];
            ans = min(ans, now_ans);
        }
        return ans;
    }
};
main()
{
    return 0;
}