#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, val;
};

int N, P;

vector<int> parent;
vector<int> rankk;

int find_set(int x){
    return parent[x]=(x==parent[x])?x:find_set(parent[x]);
}

void union_set(int x, int y){
    int a = find_set(x), b = find_set(y);
    if(find_set(a) == find_set(b)) return;

    if(rankk[a] > rankk[b]){
        parent[b] = a;
    }else{
        parent[a] = b;
        if(rankk[a] == rankk[b]){
            rankk[b]++;
        }
    }
}

int main(){
    while(cin >> N >> P){
        if(!N && !P) break;

        vector<Edge> edges;
        while(P--){
            Edge e;
            cin >> e.from >> e.to >> e.val;
            edges.push_back(e);
        }

        sort(edges.begin(), edges.end(), [](const Edge a, const Edge b){ return a.val < b.val; });

        vector<int> ans;
        rankk.assign(N, 0);
        parent.clear();
        for(int i = 0; i < N; i++){
            parent.push_back(i);
        }
        for(auto e : edges){
            if(find_set(e.from) == find_set(e.to)){
                ans.push_back(e.val);
            }else{
                union_set(e.from, e.to);
            }
        }

        if(ans.size()){
            sort(ans.begin(), ans.end());
            for(int i = 0; i < ans.size(); i++){
                cout << (i?" ":"") << ans[i];
            }
        }else{
            cout << "forest";
        }
        cout << endl;
    }
}