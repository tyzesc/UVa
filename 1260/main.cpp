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
        int n, tmp;
        cin >> n;
        vector<int> v, v2;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            v.push_back(tmp);
        }

        for(int i = 1; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < i; j++){
                if(v[j] <= v[i])
                    cnt++;
            }
            v2.push_back(cnt);
        }

        int ans = 0;
        for(int i : v2)
            ans += i;
        cout << ans << '\n';
    }
}