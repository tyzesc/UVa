// maximum flow done

#include <bits/stdc++.h>
#define MAX 2*52*52+10
#define INF 99999999

using namespace std;

struct Bank{
    int x, y;
} bank;

int cases, W, H, B, S, T;
int c[MAX][MAX];
int f[MAX][MAX];
vector<int> edges[MAX];
vector<Bank> banks;

void makeEdge(int x, int y){
    edges[x].push_back(y);
    edges[y].push_back(x);
}

void makeGraph(){
    fill(&c[0][0], &c[0][0]+sizeof(c)/sizeof(int), 0);
    fill(&f[0][0], &f[0][0]+sizeof(f)/sizeof(int), 0);

    for(int i = 1; i <= W; ++i){
        for(int j = 1; j <= H; ++j){
            c[((i*H)+j)*2][((i*H)+j)*2+1] = 1;
            makeEdge(((i*H)+j)*2, ((i*H)+j)*2+1);

            c[((i*H)+j)*2+1][(((i+1)*H)+j)*2] = 1;
            makeEdge(((i*H)+j)*2+1, ((((i+1)*H)+j)*2));
            c[((i*H)+j)*2+1][(((i-1)*H)+j)*2] = 1;
            makeEdge(((i*H)+j)*2+1, ((((i-1)*H)+j)*2));
            c[((i*H)+j)*2+1][((i*H)+j+1)*2] = 1;
            makeEdge(((i*H)+j)*2+1, (((i*H)+j+1)*2));
            c[((i*H)+j)*2+1][((i*H)+j-1)*2] = 1;
            makeEdge(((i*H)+j)*2+1, (((i*H)+j-1)*2));

            if(i == 1 || i == W || j == 1 || j == H){
                c[((i*H)+j)*2+1][T] = 1;
                makeEdge(((i*H)+j)*2+1, T);
            }
        }
    }
}

int dfs(int s){
    int minn = INF;
    vector<bool> visited(MAX, false);
    vector<int> pre(MAX, -1);
    stack<int> stack;
    stack.push(s);
    while(!stack.empty()){
        int now = stack.top(); stack.pop();
        if(visited[now])
            continue;
        visited[now] = true;
        for(int nxt : edges[now]){
            if(!visited[nxt] && c[now][nxt] > f[now][nxt]){
                pre[nxt] = now;
                stack.push(nxt);
                minn = min(minn, c[now][nxt] - f[now][nxt]);
            }
        }
    }

    if(!visited[T])
        return 0;

    for(int u = T; u != S; u = pre[u]){
        f[pre[u]][u] += minn;
        f[u][pre[u]] -= minn;
    }

    return minn;
}

int maxflow(){
    int result = 0;
    while(true){
        int ans = dfs(S);
        if(ans == 0)
            return result;
        result += ans;
    }
}

int main(){
    cin >> cases;
    while(cases--){
        cin >> W >> H >> B;
        S = 0;
        T = 1;
        for(int i = 0; i < W*H*2+2; ++i)
            edges[i].clear();
        makeGraph();

        int x, y;
        for(int k = 0; k < B; k++){
            cin >> x >> y;
            c[S][((x*H)+y)*2] = 1;
            makeEdge(S, ((x*H)+y)*2);
        }

        cout << ((maxflow() == B) ? "possible" : "not possible") << endl;
    }
}