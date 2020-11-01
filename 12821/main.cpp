/**
 * min cost maximum flow
 * */

#include <bits/stdc++.h>
#define MAXN 500+10
#define INF 9999999
using namespace std;

int N, M, u, v, d, a;

struct Edge {
    int from;
    int to;
    int cap;
    int cost;
    int flow;
} edge;

vector<Edge> edges;
vector<int> g[MAXN];

void addEdge(int x, int y, int c, int co){
    edge.from = x; edge.to = y; edge.cap = c; edge.flow = 0; edge.cost = co;
    edges.push_back(edge);
    edge.from = y; edge.to = x; edge.cap = 0; edge.flow = 0; edge.cost = -co;
    edges.push_back(edge);
    g[x].push_back(edges.size()-2);
    g[y].push_back(edges.size()-1);
}

int SPFA(int s, int t){
    int minn = INT_MAX;
    queue<int> q; q.push(s);
    vector<bool> inq(N+8, false); inq[s] = true;
    vector<int> dis(N+8, INF); dis[s] = 0;
    vector<int> pre(N+8, -1);
    while(!q.empty()){
        int u = q.front(); q.pop(); inq[u] = false;
        for(int i = 0; i < g[u].size(); i++){
            Edge& e = edges[g[u][i]];
            int v = e.to;
            if(e.cap > e.flow && dis[v] > dis[u] + e.cost){
                dis[v] = dis[u] + e.cost;
                pre[v] = g[u][i];
                minn = min(minn, e.cap - e.flow);
                if(!inq[v]) { inq[v] = true; q.push(v); }
            }
        }
    }

    if(dis[t] == INF) return -1;

    for(int u = t; u != s; u = edges[pre[u]].from){
        edges[pre[u]].flow += minn;
        edges[pre[u]^1].flow -= minn;
    }

    return dis[t];
}

int MCMF(int s, int t){
    int min_cost = 0;
    int ans;
    while((ans = SPFA(s, t)) != -1){
        min_cost += ans;
    }
    return min_cost;
}

int main(){
    int cases = 1, ans;
    while(cin >> N >> M){
        int S = N+1, T = S+1;
        // init
        for(int i = 0; i < MAXN; ++i)
            g[i].clear();
        edges.clear();

        addEdge(S, 1, 2, 0);
        addEdge(N, T, 2, 0);
        while(M--){
            cin >> u >> v >> d >> a;
            addEdge(u, v, 1, d);
            addEdge(u, v, 1, d+a);
        }
        ans = MCMF(S, T);
        cout << "Case " << cases++ << ": "<< ans << endl;
    }
}