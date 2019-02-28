// uva 247
// algorithm: floyd, DFS
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.01

/*
    地雷紀錄：
        1. 一開始測 strongly connected component ，嘗試用 Kosaraju 無法照正確的格式輸出。改用 floyd
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;
int cnt;
string names[30];

void dfs(int now, bool visited[], bool paths[30][30]){
    visited[now] = true;
    for(int i = 0; i < cnt; i++){
        if(!visited[i] && paths[now][i] && paths[i][now]){
            cout << ", " << names[i];
            dfs(i, visited, paths);
        }
    }
}

int main(){
    int N, M;
    int task = 0;
    while(true){
        cin >> N >> M;
        if(!N && !M)
            break;

        map<string, int> mapp;
        bool paths[30][30] = { false };
        bool visited[30] = { false };
        cnt = 0;
        while(M --> 0){
            string str1, str2;
            cin >> str1 >> str2;
            if( mapp.find(str1) == mapp.end() ){
                names[cnt] = str1;
                mapp[str1] = cnt++;
            }
            if( mapp.find(str2) == mapp.end() ){
                names[cnt] = str2;
                mapp[str2] = cnt++;
            }
            paths[ mapp[str1] ][ mapp[str2] ] = true;
        }

        for(int k = 0; k < N; k++){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    paths[ i ][ j ] = paths[i][j] || (paths[i][k] && paths[k][j]);
                }
            }
        }
        if(task)
            cout << endl;
        cout << "Calling circles for data set " << ++task << ":" << endl;
        for(int i = 0; i < cnt; i++){
            if(visited[i])
                continue;
            cout << names[i];
            dfs(i, visited, paths);
            cout << endl;
        }
    }
}