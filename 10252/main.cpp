#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1, s2;
    while(getline(cin, s1) && getline(cin, s2)){
        vector<char> v;
        for(int i = 0; i < s1.size(); i++){
            for(int j = 0; j < s2.size(); j++){
                if(s1[i] == s2[j] && s2[j] != '?'){
                    v.push_back(s1[i]);
                    s1[i] = '?';
                    s2[j] = '?';
                }
            }
        }

        sort(v.begin(), v.end());
        for(auto c : v)
            cout << c;
        cout << '\n';
    }
}