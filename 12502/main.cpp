#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases, x, y, c;
    cin >> cases;
    while (cases--){
        cin >> x >> y >> c;
        cout << (c*(2*x-y)/(x+y)) << endl;
    }
}