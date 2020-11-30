#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

int main(){
    int cases; cin >> cases;
    for(int T = 1; T <= cases; T++){
        int ans = 0;

        int n, m;
        cin >> n >> m;
        n -= 2; m -= 2;

        n = ((n%3)?1:0) + n/3;
        m = ((m%3)?1:0) + m/3;
        ans += m * n;
        cout << ans << '\n';
    }
}