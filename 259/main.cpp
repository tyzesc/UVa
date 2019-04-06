// uva 259
// algorithm: Maximum Flow, maxflow
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.04.07

/*
    題意理解：
        10台電腦，分別執行N個程式。每個程式都有對應可執行的電腦。
        輸出每台電腦各別執行哪種程式，若無可能則“！”。
        若以 S -> 每支程式 -> 10台電腦 -> T，架構建立 network，跑 maxflow 即可求出結果。
        設 com0～com9、S、T 分別為 點26～點37
    地雷紀錄：
        1. 55 行的 visited 要記得歸零，不然會卡迴圈。 ={0} or fill
        2. 84、85 行 在調整新的f值時，這裡的f跟基哥 slides 上的不一樣。
           依照這樣的調整模式，才能使 68 行判斷做出 Residual networks 的效果。（會把在用電腦v的程式u改到其他可行v）
    ref：
        1. http://mobcs.blogspot.com/2015/05/uva-259-software-allocation.html
*/

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int c[38][38], f[38][38], total;
int s = 36, t = 37;
string tmp;

void init(){
    total = 0;
    fill(&c[0][0], &c[0][0]+sizeof(c)/sizeof(int), 0);
    fill(&f[0][0], &f[0][0]+sizeof(f)/sizeof(int), 0);
    for(int i = 26; i < 36; i++)
        c[i][t] = 1;
}

void makeGraph(){
    if(tmp=="") return;
    int from = tmp[0] - 'A';
    int num  = tmp[1] - '0';

    c[s][from] += num;
    total += num;

    for(int k = 3; k < tmp.size()-1; k++){
        c[from][tmp[k]-'0'+26] = 1;
    }
}

int maxflow(){
    int flow = 0;

    while(true){
        bool visited[38] = {0};
        int p[38] = {-1};
        int minn = 0xDEADBEE;
        queue<int> Q, nodes;

        Q.push(s);
        visited[s] = true;
        while(!Q.empty() && !visited[t]){
            int now = Q.front(); Q.pop();

            for(int next = 0; next < 38; next++){
                if(visited[next]) continue;
                if(f[now][next] >= c[now][next]) continue;
                visited[next] = true;
                Q.push(next);
                p[next] = now;

                minn = min(minn, c[now][next] - f[now][next]);
            }
        }

        if(!visited[t]) break;

        flow += minn;

        int u = t, v;
        while(u != s){
            v = u; u = p[u];
            f[u][v] += minn;
            f[v][u] = -f[u][v];
        }
    }
    
    return flow;
}

int main(){
    while(getline(cin, tmp)){
        init();
        makeGraph();
        while(getline(cin, tmp) && tmp!="")
            makeGraph();
        int flow = maxflow();
        if(flow != total){
            cout << "!";
        }else{
            for(int com = 26; com < 36; com++){
                int pro;
                for(pro = 0; pro <= 25 && f[com][pro] == 0; pro++);
                cout << ((pro>25)?'_':((char)(pro+'A')));
            }
        }
        cout << endl;
    }
    return 0;
}