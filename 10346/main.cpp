#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

int main(){
    LL n, k;
    while(cin >> n >> k){
        LL ans = n;
        LL cnt = n;

        while(cnt >= k){
            ans += cnt / k;
            cnt = cnt % k + cnt / k;
        }

        cout << ans << '\n';
    }
}