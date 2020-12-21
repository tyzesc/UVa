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
    LL c[105][105];

    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= i; j++){
            if(i == j) c[i][j] = 1;
            else c[i][j] = c[i-1][j]*i/(i-j);
        }
    }

    LL n, m;
    while(cin >> n >> m){
        if(!n && !m) break;
        cout << n << " things taken " << m << " at a time is " << c[n][m] << " exactly.\n";
    }
}