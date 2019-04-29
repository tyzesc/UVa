// uva 12405
// algorithm: greedy
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.04.29

/*
    題意理解：
        給定一張地圖， . 代表田地 # 代表荒蕪。
        用最少稻草人保護所有田地，輸出所需要的數量。
    地雷紀錄：
        1. 要記得判斷 i < total 才吃掉字元，不然會悲劇。
    通靈解法：
        貪心貪心，看到田(i)就插下一格。能保護更多(i, i+1, i+2)。
*/
#include <iostream>

using namespace std;

void removeLastTwo(int &i, int total){
    if(i < total){
        i++;
        cin.get();
    }
    if(i < total){
        i++;
        cin.get();
    }
}

int main(){
    int T;
    cin >> T;
    for(int cases = 1; cases <= T; cases++){
        int ans = 0;
        int total;
        cin >> total;
        cin.get();
        for(int i = 0; i < total; i++){
            char c;
            c = cin.get();
            if(c=='.'){
                ans++;
                removeLastTwo(i, total);
            }
        }
        cout << "Case " << cases << ": " << ans << endl;
    }
}