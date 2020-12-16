#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

double dis(pair<double, double> a, pair<double, double> b){
    double dx = (a.first - b.first);
    double dy = (a.second - b.second);
    return sqrt(dx*dx+dy*dy);
}

int main(){
    int cases; cin >> cases;
    for(int T = 1; T <= cases; T++){
        int n;
        double a, b;
        cin >> n;
        vector<pair<double, double>> v;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }

        vector<vector<double>> d(n, vector<double>(n, 9999999));

        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            d[i][j] = dis(v[i], v[j]);
            if(d[i][j] > 10){
                d[i][j] = 9999999;
            }
        }

        for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

        double m = 0;
		for (int i = 0; i < n; ++ i)
		for (int j = 0; j < n; ++ j)
            m = max(m, d[i][j]);


        cout << "Case #" << T << ":\n";
        if(m == 9999999)
            printf("Send Kurdy\n\n");
        else
            printf("%.4f\n\n", m);
    }
}