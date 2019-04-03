// uva 10449
// algorithm: SPFA, Bellman-Ford
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.04.03

/*
    題意理解：
        根據題目定義 (busyness_to - busyness_from)^3，找到起點(點1) 到某個點的最小值。
        因為有可能有負的，所以題目有要求小於 3 的話輸出 "?"
    地雷紀錄：
        1. 原本打算用 Bellman，後來發現有點難做，改成用和上次相同的 SPFA 看入度。
        2. 當一個點被判定為負環時，其所有指向的點皆位於負環，多用一個 negQ 來執行。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

struct Edge {
    int to, cost;
};

int T, tmp, from, to, cnt;
queue<int> Hobbit, negQ;
vector<int> Busyness, Dis, Cnt;
vector<bool> inHobbit, innegQ;
vector<vector<Edge>> Edges;

int main(){
    while(cin >> T){
        Busyness.clear();
        Edges.assign(T, vector<Edge>());
        Dis.assign(T, 0xDEADBEE);
        Cnt.assign(T, 0);
        inHobbit.assign(T, false);
        innegQ.assign(T, false);
        while(T-->0){
            cin >> tmp;
            Busyness.push_back(tmp);
        }            
        cin >> T; // number of edges
        if(T != 0){
            while(T-->0){
                cin >> from >> to; from--; to--;
                Edge e;
                e.to = to;
                e.cost = pow(Busyness[to] - Busyness[from], 3);
                Edges[from].push_back(e);
            }

            Dis[0] = 0;
            Hobbit.push(0);
            inHobbit[0] = true;

            while(!Hobbit.empty()){
                int now = Hobbit.front(); Hobbit.pop(); inHobbit[now] = false;
                for(auto e : Edges[now]){
                    if(Dis[e.to] > Dis[now] + e.cost){
                        Dis[e.to] = Dis[now] + e.cost;
                        if(!inHobbit[e.to]){
                            if(++Cnt[e.to] > Busyness.size() + 1){
                                negQ.push(e.to);
                                innegQ[e.to] = true;
                                while(!negQ.empty()){
                                    int p = negQ.front(); negQ.pop();
                                    Dis[p] = -0xCAFEBEE;
                                    for(auto tmpe : Edges[p]){
                                        if(!innegQ[tmpe.to]){
                                            innegQ[tmpe.to] = true;
                                            negQ.push(tmpe.to);
                                        }
                                    }
                                }
                            }
                            if(!innegQ[e.to]){
                                Hobbit.push(e.to);
                                inHobbit[e.to] = true;
                            }
                        }
                    }
                }
                
            }
        }

        cin >> T; // test case
        cout << "Set #" << ++cnt << endl;
        while(T-->0){
            cin >> tmp; tmp--;
            if(Dis[tmp]<3 || Dis[tmp] == 0xDEADBEE) cout << "?";
            else cout << Dis[tmp];
            cout << endl;
        }
    }

}