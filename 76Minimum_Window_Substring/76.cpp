
/**
* @author : lengpi
* @date : 2020-12-03 23:47
**/

/*
滑动窗口
 */

#include <bits/stdc++.h>

using namespace std;

bool check(int * a, int * b)
{
    for(int i = 0; i < 100; ++i) {
        if(a[i] < b[i]) {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t)
{
    int nums1[100] = {0}, nums2[100] = {0};
    for(int i = 0; i < s.size(); ++i) {
        nums1[s[i] - 'A']++;
    }
    for(int i = 0; i < t.size(); ++i) {
        nums2[t[i] - 'A']++;
    }
    if(check(nums1, nums2) == 0)
        return "";
    int L = 0, R = 1e9;
    int l = 0, r = 0, nums[100] = {0};
    for(; r < s.size(); ++r) {
        nums[s[r] - 'A']++;
        if(check(nums, nums2)) {
            bool f = false;
            while(l <= r && check(nums, nums2)) {
                nums[s[l] - 'A']--;
                l++;
                f = true;
            }
            if(f) {
                l--;
                nums[s[l] - 'A']++;
            }

            if(R- L > r - l) {
                R = r;
                L = l;
            }
        }
    }
    cout << "L " << L << " R " << R << endl;
    return s.substr(L, R - L + 1);
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;
    return 0;
}
