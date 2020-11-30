#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, C, tmp;
    vector<int> v, d;
    vector<vector<bool>> dp;
    while(cin >> N){
        cin >> C;
        v.clear();
        d.assign(N+1, 0);
        dp.assign(C, vector<bool>(N+1, false));
        while(C--){
            cin >> tmp;
            v.push_back(tmp);
        }

        for(int i = 0; i < v.size(); i++){
            for(int j = N; j >= v[i]; j--){
                if(d[j] <= d[j - v[i]] + v[i]){
                    d[j] = d[j - v[i]] + v[i];
                    dp[i][j] = true;
                }
            }
        }

        for(int i = v.size()-1, j = N; i>=0; i--){
            if(dp[i][j]){
                cout << v[i] << " ";
                j -= v[i];
            }
        }
        cout << "sum:" << d[N] << endl;
    }
}