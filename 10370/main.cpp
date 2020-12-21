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
    int n, t;
    cin >> t;
    while(t--){
        cin >> n;
        double s = 0;
        
        vector<double> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            s += v[i];
        }

        double cnt = 0;
        for(double d : v)
            if(d > s/n)
                cnt++;
        cout << fixed << setprecision(3) << (cnt*100/n) << "%\n";


    }

}