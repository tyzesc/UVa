// uva 11456
// algorithm: LIS
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.25

/*
    題意理解：
        給一個序列。依順序選擇，加入頭、加入尾、或不加。使最後的序列最長，且降序排列。
        猜測大概是 LIS 類型題目。
    地雷紀錄：

    通靈解法：
        假定答案的中心點的值是 i，代表
        1. 左半邊是在原序列中的 arr[0] ~ i 最長的 LDS
        2. 右半邊是在原序列中的 i ~ arr[n-1] 最長的 LDS
        LDS 複雜度為 O(NlogN)，若檢查所有 arr 的值，複雜度就到 O(NNlogN)，會 TLE。

        將陣列反接 ex: (1 4 5 3 2) => (2 3 5 4 1 1 4 5 3 2)
        如果答案是 i，在這找 LIS 就會先得到右半邊的 LDS，然後得到左半邊的 LDS。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T, N, in;
    cin >> T;
    while(T--){
        cin >> N;
        vector<int> LIS, nums;

        while(N--){
            cin >> in;
            nums.push_back(in);
        }
        reverse(nums.begin(), nums.end());
        for(int n : nums){
            if(LIS.size() == 0 || n > LIS.back())
                LIS.push_back(n);
            else
                *lower_bound(LIS.begin(), LIS.end(), n) = n;
        }
        reverse(nums.begin(), nums.end());
        for(int n : nums){
            if(LIS.size() == 0 || n > LIS.back())
                LIS.push_back(n);
            else
                *lower_bound(LIS.begin(), LIS.end(), n) = n;
        }
        cout << LIS.size() << endl;
    }
}