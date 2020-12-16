#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(!n) break;
        deque<int> q;
        for(int i = 1; i <= n; ++i)
            q.push_back(i);
        cout << "Discarded cards:";
        for(int i = 1; i < n; ++i){
            int a = q.front(); q.pop_front();
            int b = q.front(); q.pop_front();
            if(i > 1)
                cout << ',';
            cout << ' ' << a;
            q.push_back(b);
        }
        cout << '\n';
        cout << "Remaining card: " << q.front();
        cout << '\n';
    }
}