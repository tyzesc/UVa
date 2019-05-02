// uva 11790
// algorithm: LIS, longest increasing subsequence
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.02

/*
    題意理解：
        找高度 升冪 和 降冪 最長的長度，並先輸出大的。
    地雷紀錄：

    通靈解法：
        用二分搜可以優化，內建的 lower_bound。
        找到位置後，將後方 w 格替換成自己的高度。
        輸出 size 便為答案。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Node {
    int h, w;
};

int main(){
    int T;
    cin >> T;
    for(int cases = 1; cases <= T; cases++){
        int num;
        cin >> num;
        vector<Node> nodes;
        nodes.assign(num, Node());
        for(int i = 0; i < num; i++)
            cin >> nodes[i].h;
        for(int i = 0; i < num; i++)
            cin >> nodes[i].w;

        vector<int> increasing;
        for(auto node : nodes){
            vector<int>::iterator from = lower_bound(increasing.begin(), increasing.end(), node.h);
            int minn = node.w;
            if(increasing.end()-from < node.w) minn = increasing.end()-from;
            auto to = from + minn;
            increasing.erase(from, to);
            increasing.insert(from, node.w, node.h);
        }

        reverse(nodes.begin(), nodes.end());
        vector<int> decreasing;
        for(auto node : nodes){
            vector<int>::iterator from = lower_bound(decreasing.begin(), decreasing.end(), node.h);
            int minn = node.w;
            if(decreasing.end()-from < node.w) minn = decreasing.end()-from;
            auto to = from + minn;
            decreasing.erase(from, to);
            decreasing.insert(from, node.w, node.h);
        }

        unsigned int a, b;
        a = increasing.size();
        b = decreasing.size();
        if(a >= b){
            cout << "Case " << cases << ". Increasing (" << a << "). Decreasing (" << b << ")." << endl;
        }else{
            cout << "Case " << cases << ". Decreasing (" << b << "). Increasing (" << a << ")." << endl;
        }
    }
}