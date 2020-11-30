// string substr and reverse will cause TLE
#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

bool valid(string &s, int L, int R){
    while(L < R){
        if(s[L] != s[R]) return false;
        ++L; --R;
    }
    return true;
}

int main(){
    int cases; cin >> cases;
    for(int T = 1; T <= cases; T++){
        string s;
        cin >> s;

        int dp[MAXN];

        for(int i = 0; i < s.size(); i++){
            dp[i] = i + 1;
            for(int j = 0; j <= i; j++){
                if(valid(s, j, i)){
                    dp[i] = min(dp[i], (j-1<0?1:dp[j-1]+1));
                }
            }
        }
        cout << dp[s.size()-1] << '\n';
    }
}