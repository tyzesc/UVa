// uva 11631
// algorithm: Minimum Spanning Tree (MST), Kruskal
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.04.06

/*
    題意理解：
        關閉部分電源，且還能讓所有城市連通，計算省下多少單位。
    地雷紀錄：
        1. uni 是對最頂端的 node 做，所以要 find(x) find(y)。
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int from, to, cost;
};

int M, N;
vector<int> p, csize;
vector<Edge> edges;

int find(int x){
    return ((x==p[x])?x:p[x]=find(p[x]));
}

bool uni(int x, int y){
    int a = find(x), b = find(y);
    if(a == b) return false;
    if(csize[a] > csize[b]){
        p[b] = a;
        csize[a] += csize[b];
    }else{
        p[a] = b;
        csize[b] += csize[a];
    }
    return true;
}

int main(){
    while(cin >> M, cin >> N){
        if(!M && !N) return 0;

        edges.clear();
        csize.assign(M, 1);
        p.clear();
        for(int i = 0; i < M; i++) p.push_back(i);

        while(N-->0){
            Edge e;
            cin >> e.from >> e.to >> e.cost;
            edges.push_back(e);
        }

        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){ return a.cost < b.cost; });

        int ans = 0;
        for(auto e : edges)
            if(!uni(e.from, e.to))
                ans += e.cost;

        cout << ans << endl;
    }
}