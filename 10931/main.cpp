#include <bits/stdc++.h>

using namespace std;

inline void func(long long x, long long &c){
    int index = 0;
    while((1LL<<index) <= x) index++;
    index--;
    while(index >= 0){
        if(x&(1<<index)){
            c++;
            cout << 1;
            x -= (1<<index);
        }else{
            cout << 0;
        }
        index--;
    }
}

int main(){
    long long N, M;
    while(cin >> N){
        if(N == 0)
            break;
        M = 0;
        cout << "The parity of ";
        func(N, M);
        cout << " is " << M << " (mod 2).\n";        
    }
}