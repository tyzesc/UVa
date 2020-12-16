#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

const double pi = acos(-1);

int main(){
    int cases; cin >> cases;
    for(int T = 1; T <= cases; T++){
        int n;
        cin >> n;

        double x = n * n * 6.0 / 10.0;
        double y = n / 5.0;
        y = y * y * pi;
        cout << fixed << setprecision(2) << y << ' ' << x - y << '\n';

    }
}