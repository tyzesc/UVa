// uva 315
// algorithm: DFS, finding cut point
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.05

/*
    地雷紀錄：
        1. 判定要用小於等於（ d[i] <= low[*it] ），因為當指到自己還是會被斷。
        2. low[now] = ((low[now] < d[next]) ? low[now] : d[next]);
           這裡一開始設錯，設成 ((low[now] < low[next]) ? low[now] : low[next]);
*/
#define N 100
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int total = -1;
int counts;

void visit(int now, bool bounds[N + 5][N + 5], bool visited[N + 5], int d[N + 5], int low[N + 5], vector<int> children[N + 5]){
    visited[now] = true;
    counts++;
    d[now] = counts;
    low[now] = counts;

    for(int next = 1; next <= total; next++){
        if(bounds[now][next]){
            if(visited[next]){
                low[now] = ((low[now] < d[next]) ? low[now] : d[next]);
                continue;
            } else {
                children[now].push_back(next);
                visit(next, bounds, visited, d, low, children);
                low[now] = ((low[now] < low[next]) ? low[now] : low[next]);
            }
        }
    }
    return;
}

int main(){
    while(cin >> total){
        if(!total)
            return 0;
        bool bounds[N + 5][N + 5] = { false };
        bool visited[N + 5] = { false };
        int d[N + 5];
        int low[N + 5];
        vector<int> children[N + 5];
        counts = 0;

        string path;
        int start, end;
        getline(cin, path);
        while(getline(cin, path)){
            if(path == "0")
                break;
            stringstream ss;
            ss << path;
            ss >> start;
            while(ss >> end){
                bounds[start][end] = bounds[end][start] = true;
            }
        }
        visit(1, bounds, visited, d, low, children);

        int sum = 0;

        if(children[1].size() > 1)
            sum++;

        for(int i = 2; i <= total; i++){
            for(vector<int>::iterator it = children[i].begin(); it < children[i].end(); ++it){
                if(d[i] <= low[*it]){
                    sum++;
                    break;
                }
            }
        }
        cout << sum << endl;
    }
}