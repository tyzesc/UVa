// uva 11378
// algorithm: closest pair
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.10

/*
    題意理解：
        給定 N 個座標，各自為中心點，畫出同樣邊長的正方形。
        不能相交，且要最長的（平行 x, y 軸）。
    地雷紀錄：
        第 41 行  if(it2->x - midit->x >= ans) break;
        寫成 if(midit->x - it2->x >= ans) break; 就會WA
    通靈解法：
        divide and conquer
        分左右兩邊，然後跨過中間的另外看。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
};

int DAC(vector<Node>::iterator from, vector<Node>::iterator to){
    if(from >= to) return 0xDEADBEE;
    int ans = 0xDEADBEE;
    int size = to - from;
    int mid = size / 2;
    vector<Node>::iterator midit;
    midit = from + mid;

    ans = min(DAC(from, midit), ans);
    ans = min(DAC(midit+1, to), ans);

    for(vector<Node>::iterator it = midit; it >= from; it--){
        if(midit->x - it->x >= ans) break;
        for(vector<Node>::iterator it2 = midit + 1; it2 <= to; it2++){
            if(it2->x - midit->x >= ans) break;
            int dx = abs(it->x - it2->x);
            int dy = abs(it->y - it2->y);
            ans = min(ans, max(dx, dy));
        }
    }
    return ans;
}

int main(){
    int N;
    bool first = true;
    while(cin >> N){
        vector<Node> v;
        v.clear();
        while(N--){
            Node n;
            cin >> n.x >> n.y;
            v.push_back(n);
        }
        sort(v.begin(), v.end(), [](Node a, Node b){ if(a.x != b.x) return a.x < b.x; return a.y < b.y; });
        
        int ans = DAC(v.begin(), v.end());
        cout << ans << '\n';
        first = false;
    }
}