// uva 10986
// algorithm: SSSP, Dijkstra, min-heap
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.14

/*
    地雷紀錄：
        1. Dijkstra 後，看終點的值。
        2. 在 UVa 請不要開變數叫 _start，會直接噴 CE 然後還沒有錯誤訊息。
           測超級久，最後是在 Ubuntu 16.04 上測到的錯有點可怕。
*/
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Node{
    int me, val;
    bool operator<(const Node a) const {
        return val > a.val;
    }
} node;

struct Edge{
    int to, cost;
} edge;

int _cases, N, M, S, T, _from, _end;
vector<vector<Edge> > edges;
priority_queue<Node> Hobbit;
vector<bool> inHobbit;
vector<int> dis;

int main(){
    cin >> _cases;
    for(int cases = 1; cases <= _cases; cases++){
        cin >> N >> M >> S >> T;
        edges.assign(N, vector<Edge>());
        inHobbit.assign(N, 0);
        dis.assign(N, 0xDEADBEE);
        while(!Hobbit.empty()) Hobbit.pop();
        while(M-->0){
            cin >> _from >> _end >> edge.cost;
            edge.to = _end;
            edges[_from].push_back(edge);
            edge.to = _from;
            edges[_end].push_back(edge);
        }

        node.me = S;
        node.val = 0;
        Hobbit.push(node);
        inHobbit[S] = true;
        dis[S] = 0;
        while(!Hobbit.empty()){
            node = Hobbit.top(); Hobbit.pop();
            for(auto e : edges[node.me]){
                if(dis[e.to] > dis[node.me]+e.cost){
                    dis[e.to] = dis[node.me]+e.cost;
                    inHobbit[e.to] = true;
                    Node nn = {e.to, dis[e.to]};
                    Hobbit.push(nn);
                }
            }
        }
        cout << "Case #" << cases << ": " << ((dis[T] == 0xDEADBEE)?"unreachable":to_string(dis[T])) << endl;
    }
}