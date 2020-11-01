#include <bits/stdc++.h>

using namespace std;

int calc(int x){
    if(x == 1)
        return 1;
    return ((x%2) ? calc(x*3+1) : calc(x/2)) + 1;
}

int main(){
    int x, y;
    while(cin >> x >> y){
        int ans = INT_MIN;
        for(int i = min(x, y); i <= max(x, y); i++)
            ans = max(ans, calc(i));
        cout << x << " " << y << " " << ans << endl;
    }
}