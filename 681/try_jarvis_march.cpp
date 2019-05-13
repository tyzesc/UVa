#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Node{
    int x, y;
};

vector<Node> v;

int cross(const Node &o, const Node &a, const Node &b){
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

int length2(const Node &a, const Node &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool far(const Node &o, const Node &a, const Node &b)
{
    return length2(o, a) > length2(o, b);
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


        vector<Node> ans;
        ans.clear();
        ans.push_back(v[0]);

        while(true){
            int next = 0;

            for(int i = 0; i < v.size(); i++){
                int c = cross(ans.back(), v[i], v[next]);
                if(c > 0 || (c == 0 && far(ans.back(), v[i], v[next]))){
                    next = i;
                }
            }

            if(next == 0) break;
            ans.push_back(v[next]);
        }

        cout << ans.size()+1 << endl;
        for(auto n : ans){
            cout << n.x << " " << n.y << endl;
        }
        cout << ans[0].x << " " << ans[0].y << endl;

        if(T){ cin >> N; cout << N << endl; }
    }
    
}