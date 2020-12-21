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
    int cases = 1;
    LL n, m;
    while(cin >> n >> m){
        if(n<0 && m<0) break;

        LL tmp = n;
        int cnt = 1;
        while(tmp!=1){
            if(tmp%2)
                tmp = 3*tmp+1;
            else
                tmp = tmp/2;
            if(tmp > m)
                break;
            cnt++;
        }

        cout << "Case " << cases++;
        cout << ": A = " << n << ", limit = " << m << ", number of terms = " << cnt << "\n";
    }
}