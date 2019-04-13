#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int to, cost;
};

int N, cnt;
vector<int> energy, dis;
vector<vector<int> > edges;
vector<bool> inHobbit;
queue<int> Hobbit;

int main(){
    while(cin >> N){
        if(N==-1) break;
        cnt = 0;
        dis.assign(N, -1);
        energy.assign(N, int());
        edges.assign(N, vector<int>());
        inHobbit.assign(N, false);
        while(!Hobbit.empty()) Hobbit.pop();

        for(int from = 0; from < N; from++){
            int pathnum, to;
            cin >> energy[from] >> pathnum;
            while(pathnum--){
                cin >> to; to--;
                edges[from].push_back(to);
            }
        }
        
        dis[0] = 100;
        Hobbit.push(0);

        while(!Hobbit.empty()){
            int now = Hobbit.front(); Hobbit.pop(); inHobbit[now] = false;
            for(int next : edges[now]){
                if(dis[now] + energy[next] > dis[next]){
                    dis[next] = dis[now] + energy[next];
                    if(!inHobbit[next]){
                        Hobbit.push(next);
                        inHobbit[next] = true;
                        cnt++;
                    }                    
                }
                if(cnt >= 0xBABEE){ while(!Hobbit.empty() ) Hobbit.pop(); break;}
            }
        }
        cout << ((dis[N-1]<=0)?"hopeless":"winnable") << endl;
    }
}