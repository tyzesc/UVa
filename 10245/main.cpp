// uva 10245
// algorithm: closest pair
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.17

/*
    題意理解：
        給定 N 個座標，找兩點間最短距離。（輸出至小數後第 4 位，大於等於 10000.0 要輸出 INFINITY）
    地雷紀錄：
        1. 有個測資剛好等於 10000.0，所以要大於等於時輸出 INFINITY。
        2. closestPair(v.begin(), v.end()-1); 後面要減一，才能避開一個點的情況。
    通靈解法：
        divide and conquer
        分左右兩邊，然後跨過中間的另外看。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Node{
    double x, y;
};

double calcLength(Node a, Node b){
    return sqrt(pow((b.x-a.x), 2) + pow((b.y-a.y), 2));
}

double closestPair(vector<Node>::iterator from, vector<Node>::iterator to){
    if(from >= to) return 0xDEADBEE;
    double length = 0xDEADBEE;
    int size = to - from;
    vector<Node>::iterator midit = from + size/2;
    length = min(length, closestPair(from, midit));
    length = min(length, closestPair(midit+1, to));
    
    for(vector<Node>::iterator it = midit; it >= from; it--){
        if(midit->x - it->x >= length) break;
        for(vector<Node>::iterator it2 = midit + 1; it2 <= to; it2++){
            if(it2->x - midit->x >= length) break;
            length = min(length, calcLength(*it, *it2));
        }
    }
    return length;
}

int main(){
    int N;
    while(cin >> N){
        if(!N) break;
        vector<Node> v;
        Node tmp;
        while(N--){
            cin >> tmp.x >> tmp.y;
            v.push_back(tmp);
        }

        sort(v.begin(), v.end(), [](const Node &a, const Node &b){ return a.x < b.x || ((a.x==b.x) && a.y < b.y); });
        double ans = closestPair(v.begin(), v.end()-1);
        if(ans >= 10000){
            cout << "INFINITY" << endl;
        }else{
            printf("%.4lf\n", ans);
        }
    }
}