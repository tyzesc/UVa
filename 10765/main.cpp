// uva 10765
// algorithm: DFS, finding cut points
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.12

/*
    地雷紀錄：
        1. root 的值看在 DFS tree 的 degree，其他看自己的 children 裡 low 比自己 d 大的個數 + 1
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct AnsPoint{
    int index;
    int sum;
};

int N, M;

vector<vector<int>> adjList, treePath;
vector<int> d, low, pi;
vector<AnsPoint> vans;
int timer = 0;

bool hasPath(int from, int to){
    return !(find(adjList[from].begin(), adjList[from].end(), to) == adjList[from].end());
}

void addAdj(int from, int to){
    if(hasPath(from, to))
        return;
    adjList[from].push_back(to);
    adjList[to].push_back(from);
}

void DFS(int now){
    timer++;
    d[now] = low[now] = timer;
    for(int next : adjList[now]){
        if(!d[next]){
            pi[next] = now;
            treePath[now].push_back(next);
            DFS(next);
            low[now] = min(low[now], low[next]);
        }
        else
            if(pi[now] != next)
                low[now] = min(low[now], low[next]); 
    }
}

int main(){
    while(cin >> N, cin >> M){
        if(!N && !M) return 0;

        adjList.assign(N, vector<int>());
        treePath.assign(N, vector<int>());
        d.assign(N, 0);
        low.assign(N, 0);
        pi.assign(N, 0);
        vans.clear();
        timer = 0;

        int from, to;
        while(cin >> from, cin >> to){
            if(from == -1 && to == -1) break;
            addAdj(from, to);
        }
        for(int now = 0; now < N; now++){
            if(!d[now])
                DFS(now);
        }
        for(int now = 0; now < N; now++){
            AnsPoint p = {now, 1};
            if(now == 0){
                int s = treePath[now].size();
                if(s > 0){
                    p.sum = s;
                }
            }else{
                for(int c : treePath[now]){
                    if(low[c] >= d[now]){
                        p.sum++;
                    }
                }
            }
            vans.push_back(p);
        }
        sort(vans.begin(), vans.end(), [](const AnsPoint a, const AnsPoint b){
            if(a.sum == b.sum)
                return a.index < b.index;
            return a.sum > b.sum;
        });

        for(int i = 0; i < M; i++){
            cout << vans[i].index << " " << vans[i].sum << "\n";
        }
        cout << "\n";
    }
}