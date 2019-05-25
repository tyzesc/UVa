// uva 10827
// algorithm: 2D subarray, DP
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.25

/*
    題意理解：
        找 maximum submatrix
    地雷紀錄：
        圖可以捲捲捲喔！
    通靈解法：
        二維壓到一維，就過啦：）
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Max1D(vector<int> v){
    int ans = -0xDEADBEE;
    for(int i = 0; i < v.size(); i++){
        int sum = 0;
        for(int j = i; j < v.size(); j++){
            sum += v[j];
            ans = max(sum, ans);
            if(sum <= 0) sum = 0;
        }
        for(int j = 0; j < i; j++){
            sum += v[j];
            ans = max(sum, ans);
            if(sum <= 0) sum = 0;
        }
    }
    return ans;
}

int Max2D(vector<vector<int> > &vv){
    int ans = -0xDEADBEE;
    for(int i = 0; i < vv.size(); i++){
        vector<int> colSum;
        colSum.assign(vv.size(), 0);
        for(int j = i; j < vv.size(); j++){
            for(int x = 0; x < vv.size(); x++)
                colSum[x] += vv[x][j];
            ans = max(ans, Max1D(colSum));
        }
        for(int j = 0; j < i; j++){
            for(int x = 0; x < vv.size(); x++)
                colSum[x] += vv[x][j];
            ans = max(ans, Max1D(colSum));
        }
    }
    return ans;
}

int main(){
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        vector<vector<int> > vv;
        vv.assign(N, vector<int>());
        for(auto &v : vv) v.assign(N, 0);

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> vv[i][j];
        
        cout << Max2D(vv) << endl;
    }
}