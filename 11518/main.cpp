#include <bits/stdc++.h>
#define MAXN 10000+5
using namespace std;

int N, M, L, x, y;

vector<int> v[MAXN];
vector<bool> visited(MAXN, false);

void dfs(int s){
    visited[s] = true;
    for(int n : v[s])
        if(!visited[n])
            dfs(n);
}

int main(){
    int cases;
    cin >> cases;
    while (cases--){
        cin >> N >> M >> L;
        
        for(int i = 0; i <= N; i++){
            visited[i] = false;
            v[i].clear();
        }

        while(M--){
            cin >> x >> y;
            v[x].push_back(y);
        }
        while(L--){
            cin >> x;
            dfs(x);
        }

        int ans = 0;
        for(int i = 0; i <= N; i++)
            if(visited[i])
                ans++;
        cout << ans << endl;        
    }
}