// uva 10721
// algorithm: DP
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.04.29

/*
    題意理解：
        長度為 N，切 K 塊，每塊長度不超過 M。
    通靈解法：
        Top-down 下去，當 (0, 0, ?) 時 return 1。
*/
#include <iostream>

using namespace std;

long long int dp[51][51][51];
bool visited[51][51][51];

long long int BC(int N, int K, int M){
    if(N < 0 || K < 0) return 0;
    if(visited[N][K][M]) return dp[N][K][M];
    if(!N && !K) return 1;
    long long int sum = 0;
    for(int i = 1; i <= M; i++){
        sum += BC(N-i, K-1, M);
    }
    visited[N][K][M] = true;
    return dp[N][K][M] = sum;
}

int main(){
    int N, K, M;
    while(cin >> N, cin >> K, cin >> M){
        cout << BC(N, K, M) << endl;
    }
}