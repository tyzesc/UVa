// uva 10819
// algorithm: knapsack
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.20

/*
    題意理解：
        花錢買衣服，預算內買到整體價值最高。
        ＊特殊情況：2001 元以上會回饋 200 元，所以可以買超過預算。
    地雷紀錄：
        1. 因為 DP[x] 代表 x 元可以買到的價值。所以 DP[0]=0，預算為 M 的話，vector 要開到 0~M (M+1格)
    通靈解法：
        背包問題求解，另外分兩種情況找最大值。
*/
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main(){
    int M, N, tmp;
    while(cin >> M >> N){
        vector<int> cost, value, dp;
        while(N--){
            cin >> tmp; cost.push_back(tmp);
            cin >> tmp; value.push_back(tmp);
        }

        dp.resize(M+200+1, -0xDEADBEE);
        dp[0] = 0;

        for(int i = 0; i < cost.size(); i++)
            for(int k = M+200; k >= cost[i]; k--)
                dp[k] = max(dp[k], dp[k - cost[i]] + value[i]);

        int ans = 0;
        for(int i = 0; i <= M; i++)
            ans = max(ans, dp[i]);
        for(int i = 2001; i <= M+200 && i <= dp.size(); i++)
            ans = max(ans, dp[i]);
            
        cout << ans << endl;
    }
}