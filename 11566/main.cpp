#include <bits/stdc++.h>

using namespace std;

struct Object {
    int fav;
    int price;
} object;

int main(){
    // N: friends num , X: backpack volumn, K: kinds
    int N, X, T, K, tmp;

    while(cin >> N >> X >> T >> K){
        if(N == 0 && X == 0 && T == 0 && K == 0)
            break;
        N += 1;
        X *= N;
        
        vector<Object> objects;
        for(int i = 0; i < K; i++){
            cin >> object.price >> object.fav;
            for(int j = 1; j < N; j++){
                cin >> tmp;
                object.fav += tmp;
            }
            objects.push_back(object);
        }

        int a = X / 1.1 - N*T + 1;
        vector<vector<int>> dp(2*N+1, vector<int>(a+1, 0));

        for(int k = 0; k < 2; k++) for(Object obj : objects){
            for(int i = 2*N; i > 0; i--){
                for(int j = a; j >= obj.price; j--){
                    dp[i][j] = max(dp[i][j], dp[i-1][j - obj.price] + obj.fav);
                }
            }
        }

        printf("%.2f\n", dp[2*N][a] * 1.0 / N);
    }
}