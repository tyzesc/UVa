#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

int getlevel(int x){
    int ans = 1;
    int cnt = 2;
    while(cnt-1 < x){
        cnt *= 2;
        ans++;
    }
    return ans;
}

int getamount(int level){
    int ans = 1;
    while(level--)
        ans *= 2;
    return ans - 1;
}

int main(){
    int cases; cin >> cases;
    for(int T = 1; T <= cases; T++){
        int n, a, b; cin >> n >> a >> b;
        if(a > b) swap(a, b);
        // cout << n << ' '<< getlevel(b) << endl;
        int d = getamount(n-getlevel(b)+1);
        if(d > 0) d--;
        // cout << d << endl;
        int ans = getamount(n) - d;
        cout << ans << '\n';
        
    }
}