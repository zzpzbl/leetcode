
/**
* <h3>untitled</h3>
* <p>${description}</p>
* @author : lengpi
* @date : 2020-12-03 09:39
**/

/*
 * 欧拉筛
 * */
#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 7;

int prime[N];
bool vis[N];

int Euler_sieve(int n)
{
    int cnt = 0;
    for(int i = 2; i < n; ++i) {
        vis[i] = 1;
    }

    for(int i = 2; i < n; ++i) {
        if(vis[i]) {
            prime[++cnt] = i;
        }
        for(int j = 1; j <= cnt && prime[j] * i < n; ++j) {
            vis[prime[j] * i] = 0;
            if(i % prime[j] == 0) {
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    return 0;
}
