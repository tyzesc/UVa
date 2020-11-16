#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

int n = 0, m = 0;
char g[MAXN][MAXN];
char cmd, c;
string s;

void rect(int x1, int y1, int x2, int y2, char c){
    for(int i = min(y1, y2); i <= max(y1, y2); i++){
        for(int j = min(x1, x2); j <= max(x1, x2); j++){
            g[i][j] = c;
        }
    }
}

void fillg(int x, int y, char oc, char c){
    if(x <= 0 || x > m || y <= 0 || y > n || g[y][x] != oc)
        return;
    g[y][x] = c;
    fillg(x+1, y, oc, c);
    fillg(x-1, y, oc, c);
    fillg(x, y+1, oc, c);
    fillg(x, y-1, oc, c);
};

int main(){
    int x1, x2, y1, y2;
    while(cin >> cmd){
        if(cmd == 'I'){
            cin >> m >> n;
            rect(0, 0, m, n, 'O');
        }else if(cmd == 'L'){
            cin >> x1 >> y1 >> c;
            rect(x1, y1, x1, y1, c);
        }else if(cmd == 'C'){
            rect(0, 0, m, n, 'O');
        }else if(cmd == 'V'){
            cin >> x1 >> y1 >> y2 >> c;
            rect(x1, y1, x1, y2, c);
        }else if(cmd == 'H'){
            cin >> x1 >> x2 >> y1 >> c;
            rect(x1, y1, x2, y1, c);
        }else if(cmd == 'K'){
            cin >> x1 >> y1 >> x2 >> y2 >> c;
            rect(x1, y1, x2, y2, c);
        }else if(cmd == 'F'){
            cin >> x1 >> y1 >> c;
            if(g[y1][x1] != c)
                fillg(x1, y1, g[y1][x1], c);
        }else if(cmd == 'S'){
            cin >> s; cout << s << '\n';
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    cout << g[i][j];
                }
                cout << '\n';
            }
        }else if(cmd == 'X'){
            break;
        }else{
            getline(cin, s);
        }
    }
}