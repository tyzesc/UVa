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
    int n;
    while(cin >> n){
        int k = 1, s = 1;
        while(s < n){
            k++;
            s += k;
        }
        int shift = s-n;
        if(k%2)
            cout << "TERM " << n << " IS " << shift+1 << '/' << k-shift << '\n';
        else
            cout << "TERM " << n << " IS " << k-shift << '/' << shift+1 << '\n';
        
    }
}