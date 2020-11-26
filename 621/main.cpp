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
        int ans = 0;
        string s;
        cin >> s;

        if(s == "1" || s == "4" || s == "78")
            cout << '+';
        else if(s.size() >= 2 && s.substr(s.size()-2, 2) == "35")
            cout << '-';
        else if(s.size() >= 2 && s.at(0) == '9' && s.at(s.size()-1) == '4')
            cout << '*';
        else
            cout << '?';
        
        cout << '\n';
    }
}