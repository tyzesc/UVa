// uva 10755
// algorithm: DP, 3D Maximum sum
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.04

/*
    題意理解：
        找最大的長方體和。
    地雷紀錄：
        Max1D 這裡，要考慮全負的情況。所以先加，再取 max，再歸零。
        （原本寫 加 -> 歸零 -> 取 max ，如果是全負的測資則會 return 0 而非最小負數。）
    通靈解法：
        3D -> 2D -> 1D。 O(n^5)。
*/
#include <iostream>
#include <vector>
#include <math.h>

#define lli long long int
#define MIN_LLI -9999999999

using namespace std;

int A, B, C, T;
lli Max1D(vector<lli> v){
    lli ans = MIN_LLI;
    lli sum = 0;
    for(auto i : v){
        sum += i;
        ans = max(ans, sum);
        if(sum <= 0) sum = 0;
    }
    return ans;
}

lli Max2D(vector<vector<lli>> vv){
    lli ans = MIN_LLI;
    vector<lli> sum;
    for(lli left = 0; left < B; left++){
        sum.assign(A, 0);
        for(lli i = left; i < B; i++){
            for(lli k = 0; k < A; k++){
                sum[k] += vv[k][i];
            }
            ans = max(ans, Max1D(sum));
        }
    }
    return ans;
}

lli Max3D(vector<vector<vector<lli>>> vvv){
    lli ans = MIN_LLI;
    vector<vector<lli> > sum;
    for(lli down = 0; down < C; down++){
        sum.assign(A, vector<lli>());
        for(auto &v : sum) v.assign(B, 0);
        for(lli i = down; i < C; i++){
            for(lli x = 0; x < A; x++){
                for(lli y = 0; y < B; y++){
                    sum[x][y] += vvv[x][y][i];
                }
            }
            ans = max(ans, Max2D(sum));
        }
    }
    return ans;
}


int main(){
    bool first = true;
    cin >> T;
    while(T--){
        cin >> A >> B >> C;
        vector<vector<vector<lli>>> vvv;
        vvv.assign(A, vector<vector<lli>>());
        for(auto &vv : vvv){
            vv.assign(B, vector<lli>());
            for(auto &v : vv)
                v.assign(C, 0);
        }
        for(int x = 0; x < A; x++){
            for(int y = 0; y < B; y++){
                for(int z = 0; z < C; z++){
                    cin >> vvv[x][y][z];
                }
            }
        }
        if(!first) cout << endl;
        cout << Max3D(vvv) << endl;
        first = false;
    }
}