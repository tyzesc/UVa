// uva 11264
// algorithm: greedy
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.04.26

/*
    通靈思路：
    幣值越大，下一個能選的範圍最多。
    greedy 的策略是，能選就選，不能選就換成較大的那個，保證自己的範圍是最優的。
*/
#include <iostream>

using namespace std;

int main(){
    int T, tmp;
    cin >> T;
    while(T-->0){
        int number;
        cin >> number;
        int max, last, cnt;
        max = last = cnt = 0;
        while(number-->0){
            last = tmp;
            cin >> tmp;
            if(tmp > max) cnt++;
            else max -= last;
            max += tmp;
        }
        cout << cnt << endl;
    }
}