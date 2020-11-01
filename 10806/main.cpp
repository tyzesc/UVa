// min cost max flow done.

#include <bits/stdc++.h>
#define MAXN 100+5
#define INF (100+5)*1002

using namespace std;

int N, M;

int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int cost[MAXN][MAXN];
vector<int> edges[MAXN];

pair<int, int> spfa(int s, int t){
    int minn = INT_MAX;
    queue<int> q; q.push(s);
    vector<bool> inq(MAXN, false); inq[s] = true;
    vector<int> dis(MAXN, INF); dis[s] = 0;
    vector<int> pre(MAXN, -1);

    while(!q.empty()){
        int u = q.front(); q.pop(); inq[u] = false;
        for(int v : edges[u]){
            if(flow[v][u] > 0 && dis[v] > dis[u] - cost[v][u]){
                dis[v] = dis[u] - cost[v][u];
                pre[v] = u;
                minn = min(minn, cap[u][v] - flow[u][v]);
                if(!inq[v]) { inq[v] = true; q.push(v); }
            } else if(dis[v] > dis[u] + cost[u][v] && cap[u][v] > flow[u][v]){
                dis[v] = dis[u] + cost[u][v];
                pre[v] = u;
                minn = min(minn, cap[u][v] - flow[u][v]);
                if(!inq[v]) { inq[v] = true; q.push(v); }
            }
        }
    }
    
    if(dis[t] == INF) return make_pair(-1, -1);

    for(int u = t; u != s; u = pre[u]){
        flow[pre[u]][u] += minn;
        flow[u][pre[u]] -= minn;
    }

    return make_pair(dis[t], minn);
}

int MCMF(int s, int t){
    int min_cost = 0, max_flow = 0;
    pair<int, int> ans;
    while((ans = spfa(s, t)).first != -1){
        min_cost += ans.first;
        max_flow += ans.second;
    }
    return ((max_flow == 2) ? min_cost : -1);
}

int main(){
    while(cin >> N){
        if(N == 0)
            break;
        cin >> M;
        fill(&cap[0][0], &cap[0][0]+sizeof(cap)/sizeof(int), 1);
        fill(&flow[0][0], &flow[0][0]+sizeof(flow)/sizeof(int), 0);
        fill(&cost[0][0], &cost[0][0]+sizeof(cost)/sizeof(int), INF);
        while(M--){
            int x, y, c; cin >> x >> y >> c;
            cost[x][y] = cost[y][x] = c;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        // S, T
        edges[0].push_back(1);
        edges[N].push_back(N+1);
        cost[0][1] = cost[N][N+1] = 0;
        cap[0][1] = cap[N][N+1] = 2;
        
        int ans = MCMF(0, N+1);
        if(ans == -1)
            cout << "Back to jail" << endl;
        else
            cout << ans << endl;
    }
}