#include <bits/stdc++.h>
#define MAXN 30
using namespace std;

int N;
vector<int> edges[MAXN];

int f[MAXN];

void dfs(int now, vector<bool> &visited){
    visited[now] = true;
    for(int nxt : edges[now])
        if(!visited[nxt])
            dfs(nxt, visited);
}

int solve(){
    int ans = 0;
    vector<bool> visited(MAXN, false);
    for(int i = 0; i <= N; i++){
        if(!visited[i]){
            dfs(i, visited);
            ans++;
        }
    }
    return ans;
}

int main(){
    int cases, ans;
    string tmp;
    cin >> cases; getline(cin, tmp); getline(cin, tmp);
    while (cases--){
        for(int i = 0; i < MAXN; i++)
            edges[i].clear();

        getline(cin, tmp);
        // cout << tmp << endl;
        N = tmp[0]-'A';
        while(getline(cin, tmp)){
            // cout << tmp << endl;
            if(tmp == "") break;
            edges[tmp[0]-'A'].push_back(tmp[1]-'A');
            edges[tmp[1]-'A'].push_back(tmp[0]-'A');
        }

        cout << solve() << endl ;
        if(cases != 0) cout << endl;
    }
}