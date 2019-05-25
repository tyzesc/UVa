// uva 11626
// algorithm: convex hull
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.25

/*
    題意理解：
        找到 convex hull 上的所有點
    地雷紀錄：
        在同一條線上的都要算，所以 cross 找 > 0 的就可以
    通靈解法：
        分成 lower upper 做，很好寫
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define lli long long int

using namespace std;

struct Node{
    lli x, y;
};

lli cross(Node &o, Node &a, Node &b){
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}


int main(){
    int T, N, c;
    cin >> T;
    while(T--){
        cin >> N;
        vector<Node> nodes;
        while(N--){
            Node tmp;
            cin >> tmp.x >> tmp.y; cin.get(); c = cin.get();
            if(c == (int)'Y')
                nodes.push_back(tmp);
        }

        sort(nodes.begin(), nodes.end(), [](const Node &a, const Node &b){ return a.x < b.x || (a.x==b.x && a.y < b.y); });

        vector<Node> lowerHull, upperHull;
        for(Node n : nodes){
            while(lowerHull.size() >= 2 && cross(*(lowerHull.end()-2), lowerHull.back(), n) < 0) lowerHull.pop_back();
            while(upperHull.size() >= 2 && cross(*(upperHull.end()-2), upperHull.back(), n) > 0) upperHull.pop_back();
            lowerHull.push_back(n);
            upperHull.push_back(n);
        }

        cout << lowerHull.size() + upperHull.size() - 2 << endl;
        for(Node n : lowerHull){
            cout << n.x << " " << n.y << endl;
        }
        for(vector<Node>::reverse_iterator it = upperHull.rbegin()+1; it < upperHull.rend() - 1; it++){
            cout << it->x << " " << it->y << endl;
        }
    }
}