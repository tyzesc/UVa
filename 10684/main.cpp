// uva 10684
// algorithm: DP, 1D maximum subarray sum
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.02

/*
    題意理解：
        找連續贏錢區段加總。
    通靈解法：
        區間加總小於零，就回到零開始重新計算。O(n)
*/
#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int T;
    while(cin >> T){
        if(!T) break;
        int ans, sum, tmp;
        ans = sum = 0;
        while(T--){
            cin >> tmp;
            sum += tmp;
            if(sum < 0) sum = 0;
            ans = max(ans, sum);
        }
        if(ans > 0)
            cout << "The maximum winning streak is " << ans << "." << endl;
        else
            cout << "Losing streak." << endl;
    }
}