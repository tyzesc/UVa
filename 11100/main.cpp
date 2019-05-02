// uva 11100
// algorithm: greedy
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.02

/*
    題意理解：
       每一個小背包，可以放進大背包裡，求最少的背包量。
    地雷紀錄：
        1. udebug 的測資會有很奇怪的換行問題，別理他直接上傳 uva，你會省下一個小時。
    通靈解法：
        找哪容量的背包數量最多，就是要分成的堆數。
        將排序後的資料，依序推進每堆，輸出就是答案。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    while(cin >> T){
        if(!T) break;
        vector<int> items, cnt;
        cnt.assign(10005, 0);
        int tmp, maxx, ans;
        maxx = ans = -1;

        while(T--){
            cin >> tmp;
            items.push_back(tmp);
            cnt[tmp]++;
            if(cnt[tmp] > ans){
                maxx = tmp;
                ans = cnt[tmp];
            }
        }
        sort(items.begin(), items.end());

        vector<vector<int> > vv;
        vv.assign(ans, vector<int>());
        int index = 0;
        for(auto i : items){
            vv[index%ans].push_back(i);
            index++;
        }
        cout << ans << endl;
        for(auto v : vv){
            for(int i = 0; i < v.size(); i++){
                cout << ((i)?" ":"") << v[i];
            }
            cout << endl;
        }
        cout << endl;
    }
}