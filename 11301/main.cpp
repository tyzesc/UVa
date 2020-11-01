#include <bits/stdc++.h>
#define MAXN 1005*10+100
#define INF 999999

using namespace std;

char c;
int N;

int cap[MAXN][MAXN];
int cost[MAXN][MAXN];
int flow[MAXN][MAXN];
vector<int> edges[MAXN];

void addEdge(int x, int y, int c, int cc){
    // cout << "create "<<x << " " << y << endl;
    edges[x].push_back(y);
    edges[y].push_back(x);
    cost[x][y] = c;
    cap[x][y] = cc;
}

int SPFA(int s, int t){
    int minn = INT_MAX;
    queue<int> q; q.push(s);
    vector<bool> inq(MAXN, false); inq[s] = true;
    vector<int> dis(MAXN, INF); dis[s] = 0;
    vector<int> pre(MAXN, -1);

    while(!q.empty()){
        int u = q.front(); q.pop(); inq[u] = false;
        for(int v : edges[u]){
            if(flow[v][u] > 0 && dis[v] > dis[u] - cost[v][u]){
                minn = min(minn, cap[u][v] - flow[u][v]);
                dis[v] = dis[u] - cost[v][u];
                pre[v] = u;
                if(!inq[v]){ inq[v] = true; q.push(v); }
            }else if(cap[u][v] > flow[u][v] && dis[v] > dis[u] + cost[u][v]){
                minn = min(minn, cap[u][v] - flow[u][v]);
                dis[v] = dis[u] + cost[u][v];
                pre[v] = u;
                if(!inq[v]){ inq[v] = true; q.push(v); }
            }
            // cout << u << " " << v << " " << dis[v] << " " << pre[u]<< endl;
        }
    }

    if(dis[t] == INF) return -1;

    for(int u = t; u != s; u = pre[u]){
        flow[pre[u]][u] += minn;
        flow[u][pre[u]] -= minn;
    }

    // for(int u = t, i = 0; u != s; u = pre[u], i++){
    //     printf("(%d)-", u);
    // }
    // cout << dis[t]<< endl;

    return dis[t] * minn;
}

int MCMF(int s, int t){
    int min_cost = 0;
    int val;
    while((val=SPFA(s, t)) != -1)
        min_cost += val;
    return min_cost;
}

int main(){ 
    while(cin >> N){
        if(N == 0) break;
        fill(&cap[0][0], &cap[0][0]+sizeof(cap)/sizeof(int), 0);
        fill(&flow[0][0], &flow[0][0]+sizeof(flow)/sizeof(int), 0);
        fill(&cost[0][0], &cost[0][0]+sizeof(cost)/sizeof(int), INF);
        for(int i = 0; i < MAXN; i++)
            edges[i].clear();

        cin.get(c);
        int S = 10*N+1, T = 10*N+2, SS = 10*N+3;
        map<int, bool> heads;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < N; j++){
                int index = (i*N+j)*2;
                cin.get(c);
                addEdge(index, index+1, 0, 1);
                if(c == '@'){
                    addEdge(S, index, 0, 1);
                    addEdge(index+1, index+2, 0, 1); // right
                    // up
                    if(i != 0 && !(heads[index-2*N])) addEdge(index+1, index-2*N, 0, 1); 
                    // down
                    if(i != 4 && !(heads[index+2*N])) addEdge(index+1, index+2*N, 0, 1); 
                    heads[index] = true;
                }else if(c >= '0'){
                    if(i != 4) addEdge(index+1, index + 2*N, c - '0', 1);
                    if(i != 0) addEdge(index+1, index - 2*N, c - '0', 1);
                    if(j != N-1) addEdge(index+1, index + 2, c - '0', 1);
                    if(j != 0) addEdge(index+1, index - 2, c - '0', 1);
                    if(j == N-1) {
                        addEdge(index+1, T, 0, 1);
                    // cout << "tail: " << index+1 << endl;
                        }
                }
            }
            cin.get(c);
        }

        addEdge(SS, S, 0, 3);
        int ans = MCMF(SS, T);
        cout << ans << endl;
    }
}