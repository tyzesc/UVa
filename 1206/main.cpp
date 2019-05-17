// uva 1206
// algorithm: convex hull
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.17

/*
    題意理解：
        題目好長直接看測資，猜測直接解平面的 convex hull。
    地雷紀錄：
        測資 belongs to R，所以要開 double。
        偷看別人的輸出，%.3lf 或 %g。
        在我測試過後都是可以通過的。
    通靈解法：
        Andrew's Monotone Chain，先輸出 upper 再 lower。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Node {
    double x, y;
};

double cross(Node &o, Node &a, Node &b){
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

int main(){
    string str;
    char ch;
    while(getline(cin, str)){
        stringstream ss(str);
        vector<Node> v;
        Node tmp;
        while(ss >> ch >> tmp.x >> ch >> tmp.y >> ch)
            v.push_back(tmp);

        sort(v.begin(), v.end(), [](const Node &a, const Node &b){ return a.x < b.x || ((a.x==b.x) && a.y < b.y);});

        vector<Node> lowerHull, upperHull;
        for(int i = 0; i < v.size(); i++){
            while(lowerHull.size() >= 2 && cross(lowerHull.rbegin()[1], lowerHull.rbegin()[0], v[i]) <= 0) lowerHull.pop_back();
            while(upperHull.size() >= 2 && cross(upperHull.rbegin()[1], upperHull.rbegin()[0], v[i]) >= 0) upperHull.pop_back();
            lowerHull.push_back(v[i]);
            upperHull.push_back(v[i]);
        }
        bool first = true;
        for(vector<Node>::iterator it = upperHull.begin(); it < upperHull.end(); it++){
            if(!first) printf(" ");
            printf("(%.3lf,%.3lf)", it->x, it->y);
            first = false;
        }
        for(vector<Node>::reverse_iterator it = lowerHull.rbegin()+1; it < lowerHull.rend(); it++){
            printf(" (%.3lf,%.3lf)", it->x, it->y);
        }
        printf("\n");
    }
}