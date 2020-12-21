#include <bits/stdc++.h>
#define MAXN (100000+10)
#define MN MAXN
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
#define FOR(n) for(int i = 0; i < n; i++)
using namespace std;

template<class T> void read(T &arr, int n){ for(int i = 0; i < n; i++) cin >> arr[i]; }
template<class T> void read(T &v){ for(int i = 0; i < v.size(); i++) cin >> v[i]; }

int main(){
    int t, n, a;
    cin >> t;
    for(int T = 1; T <= t; T++){
        cin >> n; n--;
        cin >> a;

        int ans[2] = {0};
        while(n--){
            int tmp; cin >> tmp;
            if(tmp == a) continue;
            ans[tmp<a]++;
            a = tmp;
        }
        

        cout << "Case " << T << ": " << ans[0] << ' ' << ans[1] << '\n';
    }
}