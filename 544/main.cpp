#include <bits/stdc++.h>
#define MAXN 205
#define INF 99999999
using namespace std;

int cases = 0;
int N, M, val, cnt;
string s;
map<string, int> mapp;

int getName(){
    cin >> s;
    if(!mapp[s]){
        mapp[s] = ++cnt;
    }
    return mapp[s];
}

struct Edge {
    int from, to, val;
    bool operator<(const Edge b){
        return val > b.val;
    }
} edge;

vector<int> pi;
int findp(int x){
    return x == pi[x] ? x : (pi[x] = findp(pi[x]));
}

int main(){
    while(cin >> N >> M){
        if(!N && !M) break;
        mapp.clear();
        cnt = 0;
        pi.clear();
        for(int i = 0; i <= N; i++)
            pi.push_back(i);

        vector<Edge> edges;
        for(int i = 0; i < M; i++){
            edge.from = getName();
            edge.to   = getName();
            cin >> edge.val;
            edges.push_back(edge);
        }

        sort(edges.begin(), edges.end());

        int s = getName(), t = getName();
        for(Edge e : edges){
            int pu = findp(e.from);
            int pv = findp(e.to);
            if(pu != pv){
                pi[pu] = pv;
                if(findp(s) == findp(t)){
                    cout << "Scenario #" << ++cases << "\n";
                    cout << e.val << " tons\n\n";
                    break;
                }
            }
        }
    }
}