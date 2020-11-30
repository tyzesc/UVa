// done 
// As mentioned before, you can assume that the graphs provided will not be cyclic and that every
// place will be reachable from the starting place. 不知為啥這句話不是代表起點會接到所有點 = =

#include <bits/stdc++.h>
#define MAXN (100+5)
using namespace std;

int cases = 1, N, S, x, y;
vector<int> v[MAXN];

void SPFA(int s){
    queue<int> q; q.push(s);
    vector<bool> inq(MAXN, false); inq[s] = true;
    vector<int> d(MAXN, INT_MIN); d[s] = 0;

    while(!q.empty()){
        int now = q.front(); q.pop(); inq[now] = false;
        for(int nxt : v[now]){
            if(d[nxt] < d[now] + 1){
                d[nxt] = d[now] + 1;
                if(!inq[nxt]){ inq[nxt] = true; q.push(nxt); }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++)
        if(d[i] > d[ans])
            ans = i;
    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", cases++, s, d[ans], ans);
}

int main(){
    while (cin >> N){
        if(N == 0) break;
        for(int i = 1; i <= N; i++)
            v[i].clear();
        cin >> S;
        while(cin >> x >> y){
            if(x == 0 && y == 0)
                break;
            v[x].push_back(y);
        }

        SPFA(S);
    }
}