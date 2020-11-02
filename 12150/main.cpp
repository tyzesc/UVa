#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    while(cin >> N){
        if(N == 0) break;
        vector<int> v(N, 0);
        int c, p;
        bool flag = false;
        for(int i = 0; i < N; i++){
            cin >> c >> p;
            if(i+p < 0 || i+p >= N || v[i+p] != 0)
                flag = true;
            else
                v[i+p] = c;
        }

        if(flag){
            cout << -1 << endl;
        }else{
            for(int i = 0; i < v.size(); i++)
                cout << ((i)?" ":"") << v[i];
            cout << endl;
        }
    }
}