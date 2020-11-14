#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases, ans, first = 1;
    string s, s1, s2;
    cin >> cases;
    getline(cin, s);
    getline(cin, s);
    while (cases--){
        getline(cin, s1);
        getline(cin, s2);
        map<char, char> mapp;
        for(int i = 0; i < s1.size(); i++)
            mapp[s1[i]] = s2[i];
        
        if(!first) cout << '\n'; first = 0;
        cout << s2 << '\n' << s1 << '\n';
        while(getline(cin, s)){
            if(s == "") break;
            for(int i = 0; i < s.size(); i++)
                s[i] = (mapp[s[i]]) ? mapp[s[i]] : s[i];
            cout << s << '\n';
        }
    }
}