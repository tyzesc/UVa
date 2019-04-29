// uva 10943
// algorithm: DP
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.04.29

/*
    題意理解：
        找到 recursive function,
        B(N,K) = i from 0 to N: sum += B(i,K-1)。
        B(N,0) = 0, B(N,1) = 1。
    地雷紀錄：
        1. DP 要每次都先取 mod，不然會炸裂。
        2. 在 sum 之前要歸零，否則炸裂。
    通靈解法：
        Bottom-up 堆上去。
*/
#include <iostream>

using namespace std;

int main(){
    long long int dp[105][105];
    for(int i = 0; i <= 100; i++){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for(int i = 2; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            dp[j][i] = 0;
            for(int k = 0; k <= j; k++){
                dp[j][i] += dp[j-k][i-1];
                dp[j][i] %= 1000000;
            }
        }
    }
    int N, K;
    while(cin >> N, cin >> K){
        if(!N && !K) break;
        cout << dp[N][K] << endl;
    }    
}