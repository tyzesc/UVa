// uva 11838
// algorithm: SCC(strongly connected component), DFS, Kosaraju
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.09

/*
    地雷紀錄：
        1. 明顯是 strongly connected component，判斷最後是否都在同一個上
        2. 嘗試測試兩種情況的花費時間，但 main2 答案一直是錯的，有空再測。前幾題都是用後面這種方式，但今天這題會 WA :(
            - path, visited 開 global，用 fill 清空
            - path, visited 用 local，然後用參數傳入
        3. 參考 https://github.com/luisfcofv/competitive-programming-book/blob/master/ch9/UVa11838.cpp 。
           發現別人只花 0.01 秒，於是將 code 換成 main3 ，時間從 0.07 -> 0.05。將 path 從 2D boolean array 改為 vector。
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int from, to, type;
bool visited[2005];
bool path[2005][2005];
vector<int> finished;

void firstDFS(int now){
    visited[now] = true;
    for(int next = 1; next <= N; next++){
        if(!visited[next] && path[now][next]){
            firstDFS(next);
        }
    }
    finished.push_back(now);
}

int ans;
void secondDFS(int now){
    visited[now] = true;
    for(int next : finished){
        if(!visited[next] && path[next][now]){
            secondDFS(next);
        }
    }
    ans++;
}

int main(){
    while(cin >> N, cin >> M){
        if(!N && !M)
            return 0;
        finished.clear();
        fill(&visited[0], &visited[0]+sizeof(visited), 0);
        fill(&path[0][0], &path[0][0]+sizeof(path), 0);
        while(M-->0){
            cin >> from >> to >> type;

            path[from][to] = true;
            if(type == 2)
                path[to][from] = true;
        }

        for(int i = 1; i <= N; i++)
            if(!visited[i])
                firstDFS(i);
        fill(&visited[0], &visited[0]+sizeof(visited), 0);
        ans = 0;
        secondDFS(finished.back());
        cout << (ans==N) << "\n";
    }
}