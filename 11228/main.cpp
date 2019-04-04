// uva 11228
// algorithm: Minimum Spanning Tree (MST), Kruskal
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.04.04

/*
    題意理解：
        兩城市距離大於 R，則需建鐵路，其餘一般道路。用前者連接的兩點在不同 STATE。
        最後輸出為 state數、道路總長度、鐵路總長度。
    地雷紀錄：
        1. 計算用的 dx, dy 需同為 double，否則最後答案 nan。
    Ref:
        1. https://wenku.baidu.com/view/527903fcb84ae45c3a358c07.html
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

struct Node {
    int x, y;
};

struct Edge {
    int from, to;
    double w;
};

struct Union {
    int p, rank;
};

int T, N;
double R;
vector<Edge> edges;
vector<Union> unions;
vector<Node> nodes;

int find(int x){
    return ((unions[x].p==x) ? x : unions[x].p=find(unions[x].p));
}

void uni(int x, int y){
    int xp = find(x), yp = find(y);
    if(unions[xp].rank > unions[yp].rank){
        unions[yp].p = xp;
    }else{
        unions[xp].p = yp;
        if(unions[xp].rank == unions[yp].rank)
            unions[yp].rank++;
    }
}

int main(){
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> N >> R;
        edges.clear();
        unions.clear();
        nodes.clear();

        int cnt = 0;
        while(N-->0){
            Node tmp;
            cin >> tmp.x >> tmp.y;
            nodes.push_back(tmp);
            Union u = {cnt++, 0};
            unions.push_back(u);
        }

        for(int n1 = 0; n1 < nodes.size(); n1++){
            for(int n2 = n1+1; n2 < nodes.size(); n2++){
                Edge e;
                e.from = n1; e.to = n2;
                double dx = abs(nodes[n1].x - nodes[n2].x);
                double dy = abs(nodes[n1].y - nodes[n2].y);
                e.w = sqrt(dx * dx + dy * dy);
                edges.push_back(e);
            }
        }

        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){ return a.w < b.w; });

        int s0;
        double s1, s2;
        s0 = nodes.size();
        s1 = s2 = 0.0;

        for(auto e : edges){
            if(find(e.from) == find(e.to)) continue;
            uni(e.from, e.to);
            if(e.w > R){
                s2 += e.w;
            }else{
                s0--;
                s1 += e.w;
            }
        }
        
        cout << "Case #" << t << ": " << s0 << " " << (int)round(s1) << " " << (int)round(s2) << endl;
    }
}