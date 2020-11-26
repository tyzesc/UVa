#include <bits/stdc++.h>
#define MAXN (1000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

string parse(string s){
    string ns = "";
    for(char d : s){
        if(d == '-') continue;
        if(d >= 'A' && d <= 'Z'){
            if(d >= 'Q') d--;
            d = (char)((d-'A')/3+2+'0');
        }
        ns = ns + d;
    }
    return ns;
}

int main(){
    int cases; cin >> cases;
    for(int T = 1; T <= cases; T++){
        int ans = 0;
        int n;
        cin >> n;
        vector<string> v;
        unordered_map<string, int> m; 
        while(n--){
            string s;
            cin >> s;
            s = parse(s);
            if(m[s] == 0)
                v.push_back(s);
            m[s] += 1;
        }

        sort(v.begin(), v.end());

        if(T != 1)
            cout << '\n';
        bool flag = false;
        for(string s : v)
            if(m[s] > 1){
                flag = true;
                cout << s.substr(0, 3) << "-" << s.substr(3, 4) << ' ' << m[s] << '\n';
            }

        if(!flag)
            cout << "No duplicates.\n";
    }
}