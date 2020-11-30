#include <bits/stdc++.h>
#define MAXN (1000 + 10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

int main(){
    int cases;
    cin >> cases;
    for (int T = 1; T <= cases; T++) {
        int ans = 0;

        int a[4];
        for (int i = 0; i < 4; i++)
            cin >> a[i];

        sort(begin(a), end(a));
        if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3])
            cout << "square\n";
        else if(a[0] == a[1] && a[2] == a[3])
            cout << "rectangle\n";
        else if(a[0]+a[1]+a[2] > a[3])
            cout << "quadrangle\n";
        else
            cout << "banana\n";
    }
}