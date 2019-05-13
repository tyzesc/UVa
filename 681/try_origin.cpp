// WA
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Node{
    int x, y;
};

vector<Node> v;

int polar(const Node &o, const Node &a, const Node &b){
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

bool polarCmp(const Node &a, const Node &b){
    int d = polar(v[0], a, b);
    if(d == 0){
        int da = (a.x-v[0].x)*(a.x-v[0].x) + (a.y-v[0].y) * (a.y-v[0].y);
        int db = (b.x-v[0].x)*(b.x-v[0].x) + (b.y-v[0].y) * (b.y-v[0].y);
        return da < db; // 改這裡就好了
    }
    return d > 0;
}

int main(){
    int T, N;
    cin >> T; cout << T << endl;
    while(T--){
        cin >> N;
        v.clear();
        while(N--){
            Node n;
            cin >> n.x >> n.y;
            v.push_back(n);
        }
        sort(v.begin(), v.end(), [](Node a, Node b){ if(a.y != b.y) return a.y < b.y; return a.x < a.x; });

        sort(v.begin() + 1, v.end(), polarCmp);

        vector<Node> ans;
        for(int i = 0; i < v.size(); i++){
            // cout << v[i].x << " " << v[i].y << endl;
            Node tmp = v[i];
            while(ans.size() > 2 && polar(*(ans.end()-2), *(ans.end()-1), tmp) <= 0)
                ans.erase(ans.end()-1);
            ans.push_back(tmp);
        }

        // cout << "ans: "<< endl;
        // for(auto n : ans ){

        //     cout << n.x << " " << n.y << endl;
        // }
        for(vector<Node>::iterator it1 = ans.begin()+1; it1 < ans.end()-1;){
            vector<Node>::iterator it0 = it1 - 1, it2 = it1 + 1;
            // cout << "compare: "  << it0->x << " " << it0->y << " " << it1->x << " " << it1->y << " " << it2->x << " " << it2->y << endl;
            if(polar(*it0, *it1, *it2) == 0){
                ans.erase(it1);
            }else{
                it1++;
            }
        }

        cout << ans.size()+1 << endl;
        for(auto n : ans){
            cout << n.x << " " << n.y << endl;
        }
        // cout << ans[0].x << " " << ans[0].y << endl;

        if(T){ cin >> N; cout << N << endl; }
    }
}