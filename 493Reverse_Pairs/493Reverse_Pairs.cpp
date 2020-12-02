#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reversePairsRecursive(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return 0;
        }
        int mid = (left + right) / 2;
        int ret1 = reversePairsRecursive(nums, left, mid);
        int ret2 = reversePairsRecursive(nums, mid + 1, right);
        int ret = ret1 + ret2;

        int i = left, j = mid + 1;
        while (i <= mid)
        {
            while (j <= right && (long long)nums[i] > 2 * (long long)nums[j])
                ++j;
            ret += (j - mid + 1);
            ++i;
        }

        vector<int> sorted(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while (p1 <= mid || p2 <= right)
        {
            if (p1 > mid)
            {
                sorted[p++] = nums[p2++];
            }
            else if (p2 > right)
            {
                sorted[p++] = nums[p1++];
            }
            else
            {
                if (nums[p1] < nums[p2])
                    sorted[p++] = nums[p1++];
                else
                    sorted[p++] = nums[p2++];
            }
        }
        for (int i = 0; i < sorted.size(); i++)
        {
            nums[left + i] = sorted[i];
        }
        return ret;
    }

    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        int ans = reversePairsRecursive(nums, 0, n - 1);
        return ans;
    }
};

int main()
{
}