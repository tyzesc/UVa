// uva 1112
// algorithm: SSSP, Dijkstra, min-heap
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.14

/*
    地雷紀錄：
        1. 每一格都放老鼠，時間內可以逃出幾隻？從終點反著跑 Dijkstra，即可求得終點到每一點的SSSP（也就是每一點到終點的最短路徑）。
        2. 這題測資比較小，但也同採用 Dijkstra + min-heap，降低複雜度。
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node{
    int me, val;
    bool operator<(const Node a) const{
        return val > a.val;
    }
} node;

struct Edge{
    int to, cost;
} edge;

int cases, N, E, T, M, from, to , ccc;
vector<vector<Edge> > edges;
vector<int> dis;
vector<bool> visited;
priority_queue<Node> Hobbit;

int main(){
    cin >> cases;
    while(cases-->0){
        cin >> N >> E >> T >> M; E--;
        edges.assign(N, vector<Edge>());
        dis.assign(N, 0xDEADBEE);
        visited.assign(N, false);
        for(int i = 0; i < M; i++){
            cin >> edge.to >> to >> edge.cost; to--; edge.to--;
            edges[to].push_back(edge);
        }
        node.me = E;
        node.val = 0;
        dis[E] = 0;
        Hobbit.push(node);
        while(!Hobbit.empty()){
            node = Hobbit.top(); Hobbit.pop();
            if(visited[node.me]) continue;
            visited[node.me] = true;
            for(auto e : edges[node.me]){
                if(dis[e.to] > dis[node.me]+e.cost){
                    Node nnode;
                    nnode.val = dis[e.to] = dis[node.me]+e.cost;
                    nnode.me = e.to;
                    Hobbit.push(nnode);
                }
            }
        }

        int counts = 0;
        for(int i = 0; i < N; i++){
            if(dis[i] <= T)
                counts++;
        }
        cout << counts << "\n";
        if(cases)
            cout << "\n";
    }
}