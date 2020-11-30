#include <bits/stdc++.h>
#define MAXN (5000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

struct Node{
    int x;
    int y;
} node;

int main(){
    int cases; cin >> cases;
    for(int T = 1; T <= cases; T++){
        int k;
        cin >> k;

        vector<Node> nodes;
        for(int i = 0; i < k; i++){
            cin >> node.x >> node.y;
            nodes.push_back(node);
        }

        sort(nodes.begin(), nodes.end(), [](const Node a, const Node b){
            if(a.x == b.x)
                return a.y < b.y;
            return a.x < b.x;
        });

        vector<Node> edges;
        for(int i = 0; i < k; i++){
            for(int j = i+1; j < k; j++){
                if(nodes[i].x != nodes[j].x)
                    break;
                node.x = nodes[i].y;
                node.y = nodes[j].y;
                edges.push_back(node);
            }
        }

        sort(edges.begin(), edges.end(), [](const Node a, const Node b){
            if(a.x == b.x)
                return a.y < b.y;
            return a.x < b.x;
        });

        LL ans = 0;
        LL now = 0;
        while(now < edges.size()){
            LL nxt = now + 1;
            while(edges[now].x == edges[nxt].x && edges[now].y == edges[nxt].y)
                nxt++;
            
            if(nxt - now >= 2)
                ans += (nxt - now) * (nxt - now - 1) / 2;        
            now = nxt;
        }

        cout << "Case " << T << ": " << ans << '\n';
    }
}