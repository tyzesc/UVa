#include <bits/stdc++.h>
#define MAXN 25
using namespace std;

int N; 
char graph[MAXN][MAXN];
bool visited[MAXN][MAXN];
set<string> sett;

void dfs(int x, int y, string s){
    // cout << x << " " << y << " " << s << " " << visited[x][y] << endl;
    if(s.size() >= 3 && s.size() <= N * N){
        sett.insert(s);
    }
    if(visited[x][y] || s.size() > N * N)
        return;
    visited[x][y] = true;
    int directs[8][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}, {-1,1}, {1,1}, {1,-1}, {-1,-1}};
    for(int i = 0; i < 8; i++){
        int nx = x+directs[i][0];
        int ny = y+directs[i][1];
        if(nx >= 0 && ny >= 0 && nx < N && ny < N)
            if(*(s.end()-1) < graph[nx][ny])
                dfs(nx, ny, s+graph[nx][ny]);
    }
    visited[x][y] = false;
}

void solve(){
    sett.clear();
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
        fill(&visited[0][0], &visited[0][0]+sizeof(visited)/sizeof(bool), false);
        dfs(i, j, string(1, graph[i][j]));
        // cout << "-------------" << endl;
    }
    vector<string> v;
    for(string s : sett)
        v.push_back(s);
    sort(v.begin(), v.end(), [](const string &a, const string &b){
        if(a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    });
    for(string s : v)
        cout << s << '\n';
}

int main(){
    int cases, ans;
    cin >> cases;
    for(int T = 0; T < cases; T++){
        cin >> N;

        for(int i = 0; i < N; i++){
            scanf("%s", &graph[i][0]);
        }

        if(T != 0) cout << '\n';
        solve();
    }
}