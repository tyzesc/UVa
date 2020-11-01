// solved tle

/**
 * 
 * 嘗試把fill改成memset 
 * SPFA -> SPFA(SLF)
 * 
 * */

#include <bits/stdc++.h>
#define MAXN (1005*10+100)
#define INF 999999

using namespace std;

char c;
int N;

int cap[MAXN][MAXN];
int cost[MAXN][MAXN];
int flow[MAXN][MAXN];
vector<int> edges[MAXN];

void addEdge(int x, int y, int c, int cc){
    edges[x].push_back(y);
    edges[y].push_back(x);
    cost[x][y] = c;
    cap[x][y] = cc;
}

int SPFA(int s, int t){
    int minn = INT_MAX;
    // queue<int> q; q.push(s);
    deque<int> q; q.push_back(s);
    vector<bool> inq(MAXN, false); inq[s] = true;
    vector<int> dis(MAXN, INF); dis[s] = 0;
    vector<int> pre(MAXN, -1);

    while(!q.empty()){
        // int u = q.front(); q.pop(); inq[u] = false;
        int u = q.front(); q.pop_front(); inq[u] = false;
        for(int v : edges[u]){
            if(flow[u][v] < 0 && dis[v] > dis[u] - cost[v][u]){
                minn = min(minn, cap[u][v] - flow[u][v]);
                dis[v] = dis[u] - cost[v][u];
                pre[v] = u;
                // if(!inq[v]){ inq[v] = true; q.push(v); }
                if(!inq[v]){ inq[v] = true; if(!q.empty() && dis[v] < dis[q.front()]) q.push_front(v); else q.push_back(v);}
            }else if(cap[u][v] > flow[u][v] && dis[v] > dis[u] + cost[u][v]){
                minn = min(minn, cap[u][v] - flow[u][v]);
                dis[v] = dis[u] + cost[u][v];
                pre[v] = u;
                // if(!inq[v]){ inq[v] = true; q.push(v); }
                if(!inq[v]){ inq[v] = true; if(!q.empty() && dis[v] < dis[q.front()]) q.push_front(v); else q.push_back(v); }
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
    while((val=SPFA(s, t)) != -1){
        min_cost += val;
    }
    return min_cost;
}

string strings[5];
int main(){
    while(cin >> N){
        if(N == 0) break;
        clock_t ssss = clock();
        int SS = 10*N+1, S = SS+1, T = S+1;

        // cout << &cap[0][0] << " " << &cap[0][0]+sizeof(cap)/sizeof(int)<< endl;
        // cout << &cap[0][0] << " " << &cap[0][0] +MAXN*MAXN<< endl;
        // cout << sizeof(cap)/sizeof(int) << " " << MAXN << " " << MAXN*MAXN<< endl;
        // fill(&cap[0][0], &cap[0][0]+sizeof(cap)/sizeof(int), 0);
        // fill(&flow[0][0], &flow[0][0]+sizeof(flow)/sizeof(int), 0);
        // fill(&cost[0][0], &cost[0][0]+sizeof(cost)/sizeof(int), INF);
        // fill(&cap[0][0], &cap[0][0] +MAXN*MAXN, 0);
        // fill(&flow[0][0], &flow[0][0] +MAXN*MAXN, 0);
        // fill(&cost[0][0], &cost[0][0] +MAXN*MAXN, INF);

        // fill(cap[0], cap[0] + MAXN*MAXN, 0);
        // fill(flow[0], flow[0] + MAXN*MAXN, 0);
        // fill(cost[0], cost[0] + MAXN*MAXN, 0);
        memset(cap, 0, T*sizeof(*cap));
        memset(flow, 0, T*sizeof(*flow));
        memset(cost, INF, T*sizeof(*cost));
        for(int i = 0; i <= T; i++){
            // memset(cap[i], 0, MAXN*sizeof(int));
            // memset(flow[i], 0, MAXN*sizeof(int));
            // memset(cost[i], INF, MAXN*sizeof(int));
            // for(int j = 0; j <= T; j++){
            //     cap[i][j] = 0;
            //     flow[i][j] = 0;
            //     cost[i][j] = INF;
            // }
            edges[i].clear();
        }
        printf("%.2f\n", (double)(clock()-ssss)/CLOCKS_PER_SEC);
        getline(cin, strings[0]);
        for(int i = 0; i < 5; i++)
            getline(cin, strings[i]);

        // head
        for(int i = 0; i < 5; i++){
            if(strings[i][0] == '@')
                addEdge(S, i*N*2, 0, 1);
        }
        // tail
        for(int i = 0; i < 5; i++){
            addEdge((i*N+(N-1))*2+1, T, 0, 1);
        }
        // mid
        int directs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < N; j++){
                int out = (i*N+j)*2+1;
                for(int k = 0; k < 4; k++){
                    int tx = i+directs[k][0];
                    int ty = j+directs[k][1];
                    if(tx < 0 || tx >= 5 || ty < 0 || ty >= N)
                        continue;
                    if(strings[tx][ty] == '@')
                        continue;
                    addEdge(out, (tx*N+ty)*2, strings[tx][ty]-'0', 1);
                }
                addEdge(out-1, out, 0, 1);
            }
        }
        addEdge(SS, S, 0, 3);

        int ans = MCMF(S, T);
        cout << ans << endl;
    }
}