#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, tmp;
    while(getline(cin, s)){
        stringstream ss(s);
        bool first = true;
        while(ss >> tmp){
            reverse(tmp.begin(), tmp.end());
            cout << (first?"":" ") << tmp;
            first = false;
        }
        cout << endl;
    }
}