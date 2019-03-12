// uva 11504
// algorithm: DFS, SCC
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.12

/*
    地雷紀錄：
        1. 用 Tarjan 找 SCC，看 in-degree 為 0 的個數。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

int cases;
int N, M, from, to, timer, cntC;
vector<vector<int>> adjList;
vector<int> d, low, component, indegree;
vector<bool> inStack;
stack<int> stackk;

void DFS(int now){
    timer++;
    d[now] = low[now] = timer;
    inStack[now] = true;
    stackk.push(now);
    for(int next : adjList[now]){
        if(!d[next]){
            DFS(next);
            low[now] = min(low[now], low[next]);
        }else{
            if(inStack[next])
                low[now] = min(low[now], d[next]);
        }
    }
    if(low[now] == d[now]){
        int tmp;
        do {
            tmp = stackk.top(); stackk.pop(); inStack[tmp] = false;
            component[tmp] = cntC;
        }while(tmp != now);
        cntC++;
    }
}

int main(){
    cin >> cases;
    while(cases-->0){
        cin >> N >> M;
        adjList.assign(N, vector<int>());
        d.assign(N, 0);
        low.assign(N, 0);
        component.assign(N, -1);
        indegree.assign(N, 0);
        inStack.assign(N, false);
        timer = 0;
        cntC = 0;
        while(M-->0){
            cin >> from >> to; from--; to--;
            adjList[from].push_back(to);
        }
        for(int i = 0; i < N; i++)
            if(!d[i])
                DFS(i);

        for(int now = 0; now < N; now++){
            for(int next : adjList[now]){
                if(component[next] != component[now])
                    indegree[component[next]]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < cntC; i++){
            if(indegree[i] == 0)
                ans++;
        }
        cout << ans << "\n";
    }
}