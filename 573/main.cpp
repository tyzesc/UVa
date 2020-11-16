#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

int main(){
    double h, u, d, f;
    
    while(cin >> h >> u >> d >> f){
        if(h == 0) break;

        int day = 1;
        double now = 999;
        bool flag = false;
        double uu = u;
        while(now > 0){
            if(day == 1) now = 0;
            // cout << day << " " << now << endl;
            if(uu >= 0){
                now += uu;
                if(now > h){
                    flag = true;
                    break;
                }
            }

            now -= d;
            if(now < 0)
                break;
            uu -= u * (0.01 * f);
            day++;
        }

        cout << (flag?"success":"failure") << " on day " << day << '\n';
    }
}