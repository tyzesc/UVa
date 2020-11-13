// done 

#include <bits/stdc++.h>
#define MAXPRIME 46341

using namespace std;

vector<bool> vis(MAXPRIME+1, false);
vector<int> primes;

int gcd(int a, int b){
    if(b == 0) return a;
    return (gcd(b, a % b));
}

int main(){
    // build
    for(int i = 2; i <= MAXPRIME; i++){
        if(vis[i]) continue;
        primes.push_back(i);
        for(int j = i; j <= MAXPRIME; j += i)
            vis[j] = true;        
    }
    long long N;
    while(cin >> N){
        if(N == 0) break;
        int ans = 0;
        long long tmp = N * (N<0?-1:1);
        for(int i = 0; i < primes.size() && tmp >= primes[i]; i++){
            int cnt = 0;
            while(tmp % primes[i] == 0){
                cnt++;
                tmp /= primes[i];
            }
            ans = gcd(ans, cnt);
        }

        if(ans == 0) ans = 1;
        // negtive number
        if(N < 0) while(ans%2==0) ans /= 2;

        cout << ans << endl;
    }
}