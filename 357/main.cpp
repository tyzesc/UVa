// uva 357
// algorithm: coin change, DP
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.22

/*
    題意理解：
        給一數字 x，找出用 1, 5, 10, 25, 50 能組合成最多幾種組合。
    地雷紀錄：

    通靈解法：
        DP 換錢問題。
*/
#include <iostream>

using namespace std;

int main(){
    int coin[5] = {1, 5, 10, 25, 50};
    long long int dp[30005], n;
    for(int i = 0; i < 30005; i++) dp[i] = 0;
    dp[0] = 1;
    for(int i = 0; i < 5; i++){
        for(int j = coin[i]; j < 30005; j++){
            dp[j] += dp[j - coin[i]];
        }
    }

    while(cin >> n){
        if(dp[n] == 1){
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        }else{
            cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << endl;
        }
    }
}