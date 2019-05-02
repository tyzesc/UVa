// uva 11908
// algorithm: DP
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.02

/*
    題意理解：
        高樓大廈貼廣告，範圍內不能重疊，要找到利益最高的值。
    地雷紀錄：
        1. 第 46、47 行，必須先做 i++，不然會導致 dp 無法正確傳下去。
        2. 要小心廣告開始位置在 0，這時減一會爆炸💥。
    通靈解法：
        Bottom-up 堆上去。
        將廣告結束時間定義為 開始+長度-1。並以此做 increasing sort。從結束點最小的開始。
        dp[i] = max(dp[i], dp[小於起點最近的] + value)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int a, b, c;
};

int main(){
    int T;
    cin >> T;
    for(int cases = 1; cases <= T; cases++){
        int lines;
        int top_floor = 0;
        cin >> lines;
        vector<Node> nodes;
        while(lines--){
            Node n;
            cin >> n.a >> n.b >> n.c;
            n.b += (n.a-1);
            top_floor = max(top_floor, n.b);
            nodes.push_back(n);
        }
        sort(nodes.begin(), nodes.end(), [](Node a, Node b){ return a.b < b.b; });
        vector<int> dp;
        dp.assign(top_floor+1, 0);

        vector<Node>::iterator it = nodes.begin();
        for(int i = 0; i <= top_floor && it != nodes.end();){
            if(it->b > i) {
                i++;
                dp[i] = dp[i-1];
                continue;
            }

            if(it->a >= 1)
                dp[i] = max(dp[i], dp[it->a - 1] + it->c);
            else
                dp[i] = max(dp[i], it->c);
            it++;
        }
        cout << "Case " << cases << ": " << dp[top_floor] << endl;
    }
}