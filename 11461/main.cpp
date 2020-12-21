#include <bits/stdc++.h>
#define MAXN (100000+10)
#define MN MAXN
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
#define FOR(n) for(int i = 0; i < n; i++)
using namespace std;

template<class T> void read(T &arr, int n){ for(int i = 0; i < n; i++) cin >> arr[i]; }
template<class T> void read(T &v){ for(int i = 0; i < v.size(); i++) cin >> v[i]; }

int main(){
    vector<int> v;
    for(int i = 1; i <= 317; i++)
        v.push_back(i*i);

    int a, b;
    while(cin >> a >> b){
        if(!a && !b) break;

        int i = 0, j = 0;
        while(a > v[i])
            i++;
        while(b >= v[j])
            j++;
        
        // cout << b << ' ' << a << endl;
        cout << j - i << '\n';
    }
}