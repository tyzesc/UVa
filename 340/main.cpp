#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

int main(){
    int g[MAXN];
    int f[MAXN];
    int n;
    int cases = 0;
    while(cin >> n){
        if(!n) break;

        for(int i = 0; i < n; i++){
            cin >> g[i];
        }
        
        cout << "Game " << ++cases << ":\n";
        while(true){
            long long cnt = 0;
            for(int i = 0; i < n; i++){
                cin >> f[i];
                cnt += f[i];
            }
            if(!cnt) break;
            int a = 0, b = 0;
            bool foundt[MAXN] = {false};
            bool foundd[MAXN] = {false};
            for(int i = 0; i < n; i++){
                if(f[i] == g[i]){
                    foundt[i] = true;
                    foundd[i] = true;
                    a++;
                }
            }
            for(int i = 0; i < n; i++){
                if(foundd[i]) continue;
                for(int j = 0; j < n; j++){
                    if(!foundt[j] && g[j] == f[i]){
                        b++;
                        foundt[j] = true;
                        break;
                    }
                }
            }
            cout << "    (" << a << "," << b << ")\n";
        }

        
    }
}