// uva 11517
// algorithm: coin change, DP
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.22

/*
    題意理解：
        給一個數字與幾個硬幣，找到大於等於這數字的組合。
    地雷紀錄：
        udebug 的測資有點問題，直接丟就過了！
    通靈解法：
        DP 換錢問題。
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T, P, N, tmp;
    cin >> T;
    while(T--){
        cin >> P >> N;
        vector<int> dom, dp;
        while(N--){
            cin >> tmp;
            dom.push_back(tmp);
        }

        dp.assign(10005, 0xDEADBEE);
        dp[0] = 0;
        for(int d : dom){
            for(int i = 10004; i >= d; i--){
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
        }

        for(int i = P; i < 10005; i++){
            if(dp[i] == 0xDEADBEE) continue;
            cout << i << " " << dp[i] << endl;
            break;
        }
    }
}