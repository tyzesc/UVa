// uva 10653
// algorithm: BFS
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.13

/*
    地雷紀錄：
        1. 走迷宮，算最短路徑。
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int x;
    int y;

    bool operator==(Node right){
        return (x == right.x) && (y == right.y);
    };
};

Node start, endd;
int R, C, X, Y, rows, num_y;
queue<Node> Q;
vector<vector<int>> mapp;

bool valid(int x, int y){
    if(x<0 || y<0 || x>=R || y>=C) return false;
    if(mapp[x][y] != 0) return false;
    if(x==start.x && y==start.y) return false;
    return true;
}

int main(){
    while(cin >> R, cin >> C){
        if(!R && !C) return 0;
        
        mapp.assign(R, vector<int>());
        for(auto it = mapp.begin(); it != mapp.end(); ++it)
            (*it).assign(C, 0);
        while(!Q.empty()) Q.pop();

        cin >> rows;
        while(rows-->0){
            cin >> X;
            cin >> num_y;
            while(num_y-->0){
                cin >> Y;
                mapp[X][Y] = -1;
            }
        }
        cin >> start.x >> start.y >> endd.x >> endd.y;
        Q.push(start);
        while(!Q.empty()){
            Node now = Q.front(); Q.pop();
            if(now == endd) break;
            int x = now.x;
            int y = now.y;
            if(valid(x+1, y)){
                Node tmp = {x+1, y};
                Q.push(tmp);
                mapp[x+1][y] = mapp[x][y] + 1;
            }
            if(valid(x-1, y)){
                Node tmp = {x-1, y};
                Q.push(tmp);
                mapp[x-1][y] = mapp[x][y] + 1;
            }
            if(valid(x, y+1)){
                Node tmp = {x, y+1};
                Q.push(tmp);
                mapp[x][y+1] = mapp[x][y] + 1;
            }
            if(valid(x, y-1)){
                Node tmp = {x, y-1};
                Q.push(tmp);
                mapp[x][y-1] = mapp[x][y] + 1;
            }
        }
        cout << mapp[endd.x][endd.y] << "\n";
    }
}