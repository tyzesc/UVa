// uva 820
// algorithm: maxflow
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.04.10

/*
    題意理解：
        輸入兩者間雙向的資料流，計算 maxflow。
        兩點間可能會有多條路徑，所以要相加。
*/
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

int N, s, t, C;
vector<vector<int> > c, f;

void init(){
    c.assign(N, vector<int>());
    for(auto &v : c)
        v.assign(N, int());
    f.assign(N, vector<int>());
    for(auto &v : f)
        v.assign(N, int());
}

int main(){
    int cnt = 0;
    while(cin >> N){
        if(!N) break;
        init();
        cin >> s >> t >> C; s--; t--;
        while(C--){
            int from, to, cost;
            cin >> from >> to >> cost; from--; to--;
            c[to][from] = (c[from][to] += cost);
        }

        // maxflow
        int flow = 0;
        while(true){
            vector<bool> visited; visited.assign(N, 0);
            vector<int> parent; parent.assign(N, -1);
            int minn = 0xDEADBEE;
            queue<int> Q;
            Q.push(s);
            visited[s] = true;
            while(!visited[t] && !Q.empty()){
                int now = Q.front(); Q.pop();
                for(int next = 0; next < N; next++){
                    if(visited[next]) continue;
                    if(c[now][next] <= f[now][next]) continue;
                    parent[next] = now;
                    Q.push(next);
                    visited[next] = true;
                    minn = min(minn, c[now][next] - f[now][next]);
                }
            }

            if(!visited[t]) break;

            int pre = parent[t];
            for(int child = t; child != s; child = parent[child], pre = parent[child]){
                f[pre][child] += minn;
                f[child][pre] -= minn;
            }
            flow += minn;
        }
        cout << "Network " << ++cnt << endl << "The bandwidth is " << flow << "." << endl << endl;
    }
}