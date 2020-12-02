#include <bits/stdc++.h>
using namespace std;

/*
2 3 5
6 7
6 0 4
*/
int compare(vector<int>& subsequence1, int index1, vector<int>& subsequence2, int index2) {
    int x = subsequence1.size(), y = subsequence2.size();
    while (index1 < x && index2 < y) {
        int difference = subsequence1[index1] - subsequence2[index2];
        if (difference != 0) {
            return difference;
        }
        index1++;
        index2++;
    }
    return (x - index1) - (y - index2);
}

vector<int> merge(vector<int>& subsequence1, vector<int>& subsequence2) {
    int x = subsequence1.size(), y = subsequence2.size();
    if (x == 0) {
        return subsequence2;
    }
    if (y == 0) {
        return subsequence1;
    }
    int mergeLength = x + y;
    vector<int> merged(mergeLength);
    int index1 = 0, index2 = 0;
    for (int i = 0; i < mergeLength; i++) {
        if (compare(subsequence1, index1, subsequence2, index2) > 0) {
            merged[i] = subsequence1[index1++];
        } else {
            merged[i] = subsequence2[index2++];
        }
    }
    return merged;
}


vector<int> maxSequence(vector<int> &nums, int k)
{
    stack<int> sta;
    int n = nums.size();
    int last = n;
    for (int i = 0; i < n; ++i)
    {
        if (sta.empty() || sta.top() >= nums[i])
        {
            if (sta.size() < k)
                sta.push(nums[i]);
        }
        else
        {
            while (!sta.empty() && sta.top() < nums[i] && n - i + sta.size() > k)
            {
                sta.pop();
            }
            if (sta.size() < k)
                sta.push(nums[i]);
        }
    }
    vector<int> ret;
    while (!sta.empty())
    {
        ret.push_back(sta.top());
        sta.pop();
    }
    reverse(ret.begin(), ret.end());
    cout << "k " << k << endl;
    cout << "size " << ret.size() << endl;
//    assert(ret.size() == k);
    return ret;
}

void maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
{
    int m = nums1.size(), n = nums2.size();
    vector<int> ans(k, 0);
    for (int i = max(0, k - n); i <= min(k, m); ++i)
    {
        vector<int> v1 = maxSequence(nums1, i);
        vector<int> v2 = maxSequence(nums2, k - i);
        vector<int> cur (merge(v1, v2));
        if(compare(ans, 0, cur, 0) < 0) {
            ans.swap(cur);
        }
    }
    for(auto x : ans) cout << "x " << x << " ";
    puts("");
}

int main()
{
    int m, n, k;
    vector<int> nums1, nums2;
    int x;
    cin >> m >> n >> k;
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        nums1.push_back(x);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        nums2.push_back(x);
    }
    maxNumber(nums1, nums2, k);
}