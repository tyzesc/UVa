// uva 10305
// algorithm: topological sort, DFS
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.02.28

/*
    地雷紀錄：
        1. 沒啥雷點，看完題目就猜拓譜。
*/
#include <iostream>
#include <string>

using namespace std;

void dfs(int now, bool paths[105][105], bool visited[], bool &first, int length){
    visited[now] = true;
    for(int i = 1; i <= length; i++){
        if(!visited[i] && paths[now][i])
            dfs(i, paths, visited, first, length);
    }
    if(first){
        cout << now;
        first = false;
    }else{
        cout << " " << now;
    }
}

int main(){
    int length, cases;
    int count;
    while(true){
        cin >> length >> cases;
        if(!length && !cases)
            return 0;
        bool paths[105][105] = { false };
        bool visited[105] = { false };
        bool first = true;
        while(cases --> 0){
            int from, to;
            cin >> to >> from;
            // cout << from<< " " << to << endl;
            if(from == 0 && to == 0)
                break;
            paths[from][to] = true;
        }
        for(int i = 1; i <= length; i++){
            if(!visited[i])
                dfs(i, paths, visited, first, length);
        }
        cout << endl;
    }
}