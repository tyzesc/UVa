// uva 10306
// algorithm: knapsack, coin change, DP
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.22

/*
    題意理解：
        給 M 種貨幣，貨幣帶有兩種價值 x, y。找到用最少的硬幣組合出 SUM(x)^2 + SUM(y)^2 == S^2
    地雷紀錄：
        1. dp[m.x][m.y] 一開始要設為 1。
    通靈解法：
        背包問題求解，一般都優化為一維的空間，但這題比較複雜點。
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Money{
    int x, y;
} tmp;

int main(){
    int T, M, S;
    cin >> T;
    while(T--){
        cin >> M >> S;
        vector<Money> v;
        vector<vector<int>> dp;
        dp.assign(S+1, vector<int>());
        for(auto &v : dp) v.assign(S+1, 0xDEADBEE);

        while(M--){
            cin >> tmp.x >> tmp.y;
            v.push_back(tmp);
            dp[tmp.x][tmp.y] = 1;
        }

        for(Money m : v){
            for(int x = m.x; x <= S; x++){
                for(int y = m.y; y <= S; y++){
                    dp[x][y] = min(dp[x][y], dp[x-m.x][y-m.y]+1);
                }
            }
        }

        int ans = 0xDEADBEE;
        for(int i = 0; i <= S; i++){
            for(int j = 0; j <= S; j++){
                if(i*i+j*j == S*S)
                    ans = min(ans, dp[i][j]);
            }
        }

        if(ans == 0xDEADBEE)
            cout << "not possible" << endl;
        else
            cout << ans << endl;
    }
}