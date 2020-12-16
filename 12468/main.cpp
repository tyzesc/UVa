#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        if(a == -1 && b == a)
            break;
        if(a > b) swap(a, b);
        cout << min(abs(a-b), abs(a+(100-b))) << '\n';
    }
}