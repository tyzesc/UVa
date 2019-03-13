// uva 924
// algorithm: BFS
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.13

/*
    地雷紀錄：
        1. BFS 算離 S 距離，然後該 level +1，然後看哪個 level 最大。
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int P, num, from, to, cases, start;
vector<vector<int>> adjList;
vector<int> dis, day;
queue<int> Q;

int main(){
    cin >> P;
    adjList.assign(P, vector<int>());
    for(from = 0; from < P; from++){
        cin >> num;
        while(num-->0){
            cin >> to;
            adjList[from].push_back(to);
        }
    }

    cin >> cases;
    while(cases-->0){
        cin >> start;
        day.assign(P, 0);
        dis.assign(P, -1);
        Q.push(start);
        dis[start] = 0;

        while(!Q.empty()){
            int now = Q.front(); Q.pop();
            for(int next : adjList[now]){
                if(dis[next] == -1){ // not visited
                    Q.push(next);
                    dis[next] = dis[now] + 1;
                    day[dis[next]]++;
                }
            }
        }

        int maxx = 0, maxxVal = 0;
        for(int k = 0; k < day.size(); k++){
            if(day[k] > maxxVal){
                maxx = k;
                maxxVal = day[k];
            }
        }

        if(maxx == 0)
            cout << 0 << "\n";
        else
            cout << maxxVal << " " << maxx << "\n";
    }
}