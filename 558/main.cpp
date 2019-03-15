// uva 558
// algorithm: Dijkstra, finding negative rings
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.15

/*
    地雷紀錄：
        1. 若圖裡有負環則 possible。
        2. 跑的同時，紀錄進入該點次數，若超過 n-1 則代表有負環。
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge{
    int to, cost;
} edge;

struct Node{
    int me, val;
    bool operator<(const Node a) const {
        return val > a.val;
    }
} node;

int cases, N, M, _from, _to, _cost, total;
vector<vector<Edge> > edges;
priority_queue<Node> Hobbit;
vector<int> dis;
vector<int> in;


int main(){
    cin >> cases;
    while(cases-->0){
        cin >> N >> M;
        edges.assign(N, vector<Edge>());
        in.assign(N, 0);
        while(!Hobbit.empty()) Hobbit.pop();
        dis.assign(N, 0xDEADBEE);
        total = 0;

        while(M-->0){
            cin >> _from >> _to >> _cost;
            edge.to = _to;
            edge.cost = _cost;
            edges[_from].push_back(edge);
        }

        node.me = 0;
        node.val = 0;
        dis[node.me] = 0;
        Hobbit.push(node);

        bool flag = false;
        while(!Hobbit.empty()){
            node = Hobbit.top(); Hobbit.pop();
            for(auto e : edges[node.me]){
                if(dis[e.to] > dis[node.me]+e.cost){
                    dis[e.to] = dis[node.me]+e.cost;
                    if(++in[e.to] > N - 1){
                        flag = true;
                        break;
                    }
                    Node nn = {e.to, dis[node.me]+e.cost};
                    Hobbit.push(nn);
                }
            }
            if(flag) break;
        }
        if(flag)
            cout << "possible\n";
        else
            cout << "not possible\n";        
    }
}