// uva 10337
// algorithm: DP
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.04.28

/*
    題意理解：
        高度 0 ~ 9，開始結束都是 0。
    通靈解法：
        Bottom-up 選最小疊上去，輸出終點的高度 0。
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int mile;
        cin >> mile;
        int n = mile / 100;
        int w[100000/100 + 5][10 + 5];
        for(int j = 9; j >= 0; j--){
            for(int i = 0; i < n; i++){
                cin >> w[i][j];
            }
        }

        int dp[100000/100 + 5][10 + 5];
        fill(&dp[0][0], &dp[0][0] + sizeof(dp)/sizeof(int), 0xDEADBEE);
        dp[0][0] = 0;

        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 10; j++){
                // up
                if(j+1 <= 9) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+60-w[i][j]);
                // hold
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+30-w[i][j]);
                // down
                if(j-1 >= 0) dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j]+20-w[i][j]);
            }
        }
        cout << dp[n][0] << endl << endl;
    }
}