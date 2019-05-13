// uva 681
// algorithm: convex hull
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.13

/*
    題意理解：
        給一堆點，找凸包。
    地雷紀錄：
        一般的演算法都是以 x 排序，但輸出要以 y。
        所以找到後，另外跑一次找起點，逆時針輸出。
    通靈解法：
        Andrew's Monotone Chain，之後再找起點。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Node{
    long long int x, y;
};

vector<Node> v;

long long int cross(const Node &o, const Node &a, const Node &b){
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}

int main(){
    long long int T, N;
    cin >> T; cout << T << endl;
    while(T--){
        cin >> N;
        v.clear();
        while(N--){
            Node n;
            cin >> n.x >> n.y;
            v.push_back(n);
        }
        sort(v.begin(), v.end(), [](Node a, Node b){ if(a.x != b.x) return a.x < b.x; return a.y < b.y; });

        vector<Node> upperHull, lowerHull;
        for(long long int i = 0; i < v.size(); i++){
            while(upperHull.size() >= 2 && cross(*(upperHull.end()-2), upperHull.back(), v[i]) >= 0) upperHull.pop_back();
            while(lowerHull.size() >= 2 && cross(*(lowerHull.end()-2), lowerHull.back(), v[i]) <= 0) lowerHull.pop_back();
            upperHull.push_back(v[i]);
            lowerHull.push_back(v[i]);
        }

        vector<Node> answer;
        vector<Node>::iterator start = lowerHull.begin();
        for(vector<Node>::iterator it = lowerHull.begin()+1; it < lowerHull.end(); it++){
            if(it->y >= start->y) break;
            start = it;
        }

        cout << lowerHull.size() + upperHull.size() - 1 << endl;
        
        for(vector<Node>::iterator it = start; it < lowerHull.end(); it++){
            cout << it->x << " " << it->y << endl;
        }
        for(vector<Node>::reverse_iterator it = upperHull.rbegin()+1; it < upperHull.rend(); it++){
            cout << it->x << " " << it->y << endl;
        }
        for(vector<Node>::iterator it = lowerHull.begin()+1; it <= start; it++){
            cout << it->x << " " << it->y << endl;
        }

        if(T){ cin >> N; cout << N << endl; }
    }
}