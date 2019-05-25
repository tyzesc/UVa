// uva 11951
// algorithm: 2D subarray, DP
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.25

/*
    題意理解：
        要買長方形的地，給二維的座標，每一格的價格。
        找能買到的最大土地，若同樣大小，輸出價格小的。
    地雷紀錄：

    通靈解法：
        將二維壓到一維，能減少計算量。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T, N, M, K, cas = 1;
    cin >> T;
    while(cin >> N >> M >> K){
        vector<vector<int> > vv;
        vv.assign(N, vector<int>());
        for(auto &v : vv) v.assign(M, 0);

        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                cin >> vv[i][j];

        int area = 0, cost = 0;
        for(int col = 0; col < M; col++){
            vector<int> colSum;
            colSum.assign(N, 0);
            for(int i = col; i < M; i++){
                for(int j = 0; j < N; j++)
                    colSum[j] += vv[j][i];
                
                for(int from = 0; from < N; from++){
                    int pCost = 0;
                    for(int to = from; to < N; to++){
                        pCost += colSum[to];
                        if(pCost > K) break;
                        int pArea = (i - col + 1) * (to - from + 1);
                        if(pArea > area){
                            area = pArea;
                            cost = pCost;
                        }
                        if(pArea == area){
                            cost = min(cost, pCost);
                        }
                    }
                }
            }
        }

        printf("Case #%d: %d %d\n", cas++, area, cost);
    }
}