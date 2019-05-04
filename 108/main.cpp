// uva 108
// algorithm: DP, 2D Maximum sum
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.04

/*
    題意理解：
        找最大的 submatrix 和。
    通靈解法：
        先將二維降至一維，就能用 O(n^3) 去解。
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int Max1D(vector<int> v){
    int ans = -9999999;
    int sum = 0;
    for(int i : v){
        sum += i;
        if(sum <= 0) sum = 0;
        ans = max(ans, sum);
    }
    return ans;
}

int Max2D(vector<vector<int> > vv){
    int ans = -9999999;
    vector<int> sum;
    for(int left = 0; left < vv.size(); left++){
        sum.assign(vv.size(), 0);
        for(int i = left; i < vv.size(); i++){
            for(int k = 0; k < vv.size(); k++){
                sum[k] += vv[i][k];
            }
            ans = max(ans, Max1D(sum));
        }
    }
    return ans;
}

int main(){
    int N;
    while(cin >> N){
        vector<vector<int> > vv;
        vv.assign(N, vector<int>());
        for(auto &v : vv) v.assign(N, int());

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> vv[i][j];
            }
        }

        cout << Max2D(vv) << endl;
    }
}