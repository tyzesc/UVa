// uva 872
// algorithm: backtracking, DFS
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.02.28

/*
    地雷紀錄：
        1. 最後輸出要照字典排序，補個 sort 解決
        2. 從一開始 array 無法 pass by value，到改用 vector，到嘗試 visit 完回來把該點 visited 改回 false。
        3. 使用 backtracking 有個重點是，要保證加進來的元素符合規範。所以在 note 3: 位置，要先避免之後出現比當前優先度更前的。
*/
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

// queue<int> tasks;
int caselength = 0;
int chars[26];

bool noAnswer = true;
void visit(bool paths[26][26], int now, vector<int> has, vector<bool> visited){
    has.push_back(now);
    visited[now] = true;
    if(has.size() == caselength){
        noAnswer = false;
        cout << (char)(has[0]+'A');
        for(int i = 1; i < has.size(); i++)
            cout << " " << (char)(has[i]+'A');
        cout << endl;
        return;
    }

    // note 3:
    // make sure that: after adding this element into answer array, there is no element smaller than this.
    for(int i = 0; i < caselength; i++){
        int next = chars[i];
        if(!visited[next] && paths[now][next])
            return;
    }

    for(int i = 0; i < caselength; i++){
        int next = chars[i];
        // for(int k = 0; k < has.size(); k++)
        //     cout << (char)('A'+has[k]) << " ";
        // cout << "try to go from "<< (char)(now+'A') << " to " << (char)(next+'A') << " flag: " << !visited[next] << " " << !paths[next][now] << ". Now visited:";
        // for(int k = 0; k < visited.size(); k++)
        //     if(visited[k])
        //         cout << " " << (char)(k+'A');
        // cout << endl;
        if(!visited[next] && !paths[now][next]){
            // cout << "add answer path that from " << (char)(next+'A') << " to " << (char)(now+'A') << endl;
            // cout << &visited << endl;
            visit(paths, next, has, visited);
            visited[next] = false;
        }
    }
}

int main(){
    bool first = true;
    string tmp;
    int cases;
    cin >> cases;
    getline(cin, tmp);
    while(cases --> 0){
        if(!first)
            cout << endl;
        first = false;
        noAnswer = true;
        caselength = 0;
        // bool used[26] = {false};
        bool paths[26][26] = {false};
       
        getline(cin, tmp); // empty line;
        getline(cin, tmp);
        // cout << tmp << endl;

        stringstream ss;
        ss << tmp;

        while(ss >> tmp){
            // used[ tmp[0]- 'A'] = true;
            chars[caselength++] = tmp[0] - 'A';
            // cout << tmp[0] << endl;
        }
        sort(chars, chars+caselength); // ******************************* for print in order
        getline(cin, tmp);
        ss.clear();
        ss << tmp;
        
        while(ss >> tmp){
            // cout << tmp << endl;
            paths[ tmp[2] - 'A' ][ tmp[0] - 'A' ] = true;
            // tasks.push(tmp[0]-'A');
            // cout <<  tmp[2] - 'A'  << " " <<  tmp[0] - 'A' << endl;
            // cout << paths[ tmp[2] - 'A' ][ tmp[0] - 'A' ] << endl;
        }



        for(int i = 0; i < caselength; i++){
            vector<int> has;
            vector<bool> visited;
            visited.resize(26);
            visit(paths, chars[i], has, visited);
        }
        if(noAnswer)
            cout << "NO" << endl;
    }
}