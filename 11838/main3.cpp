// uva 11838
// algorithm: SCC(strongly connected component), DFS, Kosaraju
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.09

/*
    地雷紀錄：
        1. 明顯是 strongly connected component，判斷最後是否都在同一個上
        2. 嘗試測試兩種情況的花費時間，但 main2 答案一直是錯的，有空再測。前幾題都是用後面這種方式，但今天這題會 WA :(
            - path, visited 開 global，用 fill 清空
            - path, visited 用 local，然後用參數傳入 DFS function
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int from, to, type;
vector<bool> visited;
vector<vector<int>> adj1;
vector<vector<int>> adj2;
vector<int> finished;

void firstDFS(int now){
    visited[now] = true;
    for(int next : adj1[now])
        if(!visited[next])
            firstDFS(next);
    finished.push_back(now);
}

int ans;
void secondDFS(int now){
    visited[now] = true;
    for(int next : finished)
        if(!visited[next] && find(adj2[now].begin(), adj2[now].end(), next) != adj2[now].end())
            secondDFS(next);
    ans++;
}

int main(){
    while(cin >> N, cin >> M){
        if(!N && !M)
            return 0;
        finished.clear();
        adj1.assign(N, vector<int>());
        adj2.assign(N, vector<int>());
        visited.assign(N, 0);
        while(M-->0){
            cin >> from >> to >> type;
            from--; to--;
            adj1[from].push_back(to);
            adj2[to].push_back(from);
            if(type == 2){
                adj2[from].push_back(to);
                adj1[to].push_back(from);
            }
        }

        for(int now = 0; now < N; now++){
            if(!visited[now])
                firstDFS(now);
        }
        
        visited.assign(N, 0);
        ans = 0;
        secondDFS(finished.back());
        cout << (ans==N) << "\n";
    }
}