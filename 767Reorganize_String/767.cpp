//
// Created by lengpi on 2020/12/2.
//

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
}

string reorganizeString(string S) {
    int n = S.size();
    int num[27] = {0};
    int imax = 0;
    for(int i = 0; i < n; ++i) {
        num[S[i] - 'a']++;
        imax = max(imax, num[S[i] - 'a']);
    }
    if(imax > (n + 1) / 2) return "";
    vector<pair<int, int> > v;
    char ans[600] = {'\0'};
    for(int i = 0; i < 26; ++i) v.push_back({num[i], i});
    sort(v.begin(), v.end(), cmp);
    int pos = 0;
    for(int i = 0; i < v.size(); ++i) {
       while(v[i].first) {
                ans[pos] = v[i].second + 'a';
                pos += 2;
                if(pos >= n) pos = 1;
                v[i].first--;
            }
    }
    for(int i = 0; i < n; ++i) cout << ans[i];
    puts("");
    string ret(ans);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << reorganizeString(s) << endl;
}

