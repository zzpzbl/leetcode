
/**
* @author : lengpi
* @date : 2020-12-05 10:12
**/

#include <bits/stdc++.h>

using namespace std;

static bool cmp(int &a, int &b) {
    return a > b;
}

int leastInterval(vector<char>& tasks, int n) {
    int len=tasks.size();
    int num[26] = {0};
    for(auto x : tasks) {
        num[x - 'A']++;
    }
    sort(num, num + 26, cmp);
    int cnt = 1, ans = 0;
    while(cnt < 26 && num[cnt] == num[0]) ++cnt;
    ans = max(len, (num[0] - 1) * (n + 1) + cnt);
    return ans;
}

