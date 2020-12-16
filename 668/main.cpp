#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

int main(){
    int cases; cin >> cases;
    for(int T = 1; T <= cases; T++){
        int n;
        cin >> n;

        vector<int> v;
        int k = 2, p = n;
        while(p >= k){
            v.push_back(k);
            p -= k;
            k++;
        }

        int index = v.size() - 1;
        while(p){
            v[index]++;
            p--;
            index += v.size();
            index--;
            index %= v.size();
        }

        if(T != 1)
            cout << '\n';
        for(int i = 0; i < v.size(); i++)
            cout << (i?" ":"") << v[i];
        cout << '\n';
    }
}