// uva 11096
// algorithm: convex hull
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.13

/*
    題意理解：
        給一堆點，找凸包。會輸入橡皮筋的長度，如果圍起來的邊沒大於此長，輸出橡皮筋的長。
    地雷紀錄：
        要 long long int
    通靈解法：
        Andrew's Monotone Chain，加總長度。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Node{
    long long int x, y;
};

long long int cross(const Node &o, const Node &a, const Node &b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double length(const Node &a, const Node &b){
    long long int dx = b.x - a.x;
    long long int dy = b.y - a.y;
    return sqrt((dx*dx)+(dy*dy));
}

int main(){
    long long int T;
    cin >> T;
    while(T--){
        double L;
        long long int N;
        cin >> L >> N;
        vector<Node> v;
        while(N--){
            Node n;
            cin >> n.x >> n.y;
            v.push_back(n);
        }

        sort(v.begin(), v.end(), [](const Node &a, const Node &b){ return ((a.x < b.x) || (a.x == b.x && a.y < b.y)); });

        vector<Node> lowerHull, upperHull;
        for(long long int i = 0; i < v.size(); i++){
            while(lowerHull.size() >= 2 && cross(*(lowerHull.end()-2), lowerHull.back(), v[i]) <= 0) lowerHull.pop_back();
            while(upperHull.size() >= 2 && cross(*(upperHull.end()-2), upperHull.back(), v[i]) >= 0) upperHull.pop_back();
            lowerHull.push_back(v[i]);
            upperHull.push_back(v[i]);
        }

        double sum = 0;
        for(long long int i = 0; i < lowerHull.size() - 1; i++){
            sum += length(lowerHull[i], lowerHull[i+1]);
        }
        for(long long int i = 0; i < upperHull.size() - 1; i++){
            sum += length(upperHull[i], upperHull[i+1]);
        }
        printf("%.5f\n", (max(sum, L)));
    }
}