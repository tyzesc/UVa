#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<double>
#define VVI vector<vector<double>>
#define LL long long
using namespace std;

int n, m;
VVI vvi;
unordered_map<string, int> mapp;
int cnt = 0;

int getIndex(string s){
    if(mapp[s])
        return mapp[s];
    return mapp[s] = ++cnt;
}

bool spfa(int s){
    queue<int> q; q.push(s);
    vector<bool> inq(n+1, false); inq[s] = true;
    vector<double> dis(n+1, 0); dis[s] = 1;
    while(!q.empty()){
        int now = q.front(); q.pop(); inq[now] = false;
        for(int i = 1; i <= n; i++){
            if(vvi[now][i] == -9999999)
                continue;
            if(dis[i] < dis[now] * vvi[now][i]){
                dis[i] = dis[now] * vvi[now][i];
                if(!inq[i]){
                    inq[i] = true;
                    q.push(i);
                }
                if(i == 1)
                    return true;
            }
        }
    }
    return false;
}


int main(){
    int T = 0;
    while(cin >> n){
        if(n == 0) break;
        string ans = "", tmps;
        mapp.clear();
        cnt = 0;

        for(int i = 0; i < n; i++){
            cin >> tmps;
            getIndex(tmps);
        }

        cin >> m;
        vvi = VVI(n+1, VI(n+1, -9999999));
        for(int i = 0; i < m; i++){
            string s1, s2;
            double d;
            cin >> s1 >> d >> s2;
            vvi[getIndex(s1)][getIndex(s2)] = d;
        }

        cout << "Case " << ++T << ": " << (spfa(1)?"Yes":"No") << '\n';
    }
}