// uva 10616
// algorithm: knapsack
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.21

/*
    題意理解：
        給定 N 個數字，找出其中 M 個數，能剛好被 D 整除。
    地雷紀錄：
        1. 因為是除以 D，所以 vector 不用開滿到最大加總，到 D-1 即可。
        2. (A + B) % D == ((A%D)+(B%D)) % D
        3. 測資有可能是負的，所以在 28 行多加一次。
    通靈解法：
        有點像背包問題，dp[x][y] 定義為，用 x 數能組合出 y 的可能性個數。
        dp[0][0] 為零，反著堆到 dp[M][?]，然後加總即可。（從 M-1 開始到 0）
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
void solve(int D, int M, int cas){
    int ans = 0, sum = 0;
    vector<int> mod;
    for(int i : num){
        int tmp = (i % D + D) % D;
        sum += tmp;
        mod.push_back(tmp);
    }
    
    vector<vector<int> > dp;
    dp.assign(M+1, vector<int>());
    for(auto &v : dp) v.assign(sum+1, 0);
    dp[0][0] = 1;
    
    for(int n : mod)
        for(int i = M - 1; i >= 0; i--)
            for(int k = 0; k <= sum-n; k++)
                dp[i + 1][k + n] += dp[i][k];
                
    for(int i = 0; i <= sum; i += D)
        ans += dp[M][i];
    printf("QUERY %d: %lli\n", cas, ans);
}

int main(){
    int N, Q, tmp, D, M, cas = 1;
    while(cin >> N >> Q){
        if(!N && !Q) break;
        num.clear();
        while (N--){
            cin >> tmp;
            num.push_back(tmp);
        }
        printf("SET %d:\n", cas++);
        for(int q = 1; q <= Q; q++){
            cin >> D >> M;
            solve(D, M, q);
        }
    }
}