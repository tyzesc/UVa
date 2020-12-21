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
    string s, tmp;
    while(getline(cin, s)){
        bool b = false;
        int cnt = 0;
        for(char c : s){
            if(isalpha(c) && !b){
                b = true;
                cnt++;
            }else if(!isalpha(c) && b){
                b = false;
            }
        }
        cout << cnt << '\n';
    }
}