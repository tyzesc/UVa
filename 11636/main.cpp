// terminate when input is negative. done
#include <bits/stdc++.h>

using namespace std;

int mypow(int x, int p){
    int s = 1;
    for(int i = 0; i < p; i++)
        s *= x;
    return s;
}

int main(){
    int T = 0, N;
    while(cin >> N){
        if(N < 0) break;
        int k = 0;
        while(mypow(2, k) < N) k++;
        cout << "Case " << ++T << ": " << k << endl;
    }
}