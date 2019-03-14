#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int cases, N, M, tmp;
int HYMDS[1005][1005];

struct Node {
    int x, y, dis;
    bool operator<(const Node& y) const {
        return dis > y.dis;
    }
    Node(int q = 0, int w = 0, int e = 0){
        x = q;
        y = w;
        dis = e;
    }
};

int _px_VM_xd_[4][2] {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
priority_queue<Node> Hobbit;

int main(){
    cin >> cases;
    while(cases --> 0){
        cin >> N >> M;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> tmp;
                HYMDS[i][j] = tmp;
            }
        }

        if(N==1 && M==1){
            printf("%d\n", HYMDS[0][0]);
            continue;
        }
        while(!Hobbit.empty()) Hobbit.pop();

        Hobbit.emplace(0, 0, HYMDS[0][0]);
        HYMDS[0][0] = 0xBEEF;
        while(!Hobbit.empty()){
            bool isFind = false;
            Node tmp = Hobbit.top(); Hobbit.pop();
            for(auto& v : _px_VM_xd_){
                int nx = tmp.x + v[0];
                int ny = tmp.y + v[1];
                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                if(nx==N-1 && ny==M-1){
                    isFind = true;
                    printf("%d\n", tmp.dis + HYMDS[nx][ny]);
                    break;
                }
                if(HYMDS[nx][ny] >= 0xBEEF) continue;
                Hobbit.emplace(nx, ny, tmp.dis + HYMDS[nx][ny]);
                HYMDS[nx][ny] = 0xBEEF;
            }
            if(isFind) break;
        }
    }
}