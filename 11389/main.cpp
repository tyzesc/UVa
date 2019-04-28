// uva 11389
// algorithm: greedy
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.04.26

/*
    通靈思路：
    將一個從大到小，另一個小到大。兩兩配合的所有情況會得最小值。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, D, R, tmp;
    while(true){
        cin >> N >> D >> R;
        if(!N && !D && !R) break;
        vector<int> morning, evening;
        for(int i = 0; i < N; i++){
            cin >> tmp;
            morning.push_back(tmp);
        }
        sort(morning.begin(), morning.end(), greater<int>());
        for(int i = 0; i < N; i++){
            cin >> tmp;
            evening.push_back(tmp);
        }
        sort(evening.begin(), evening.end());

        int sum = 0;
        for(vector<int>::iterator it = morning.begin(), it2 = evening.begin(); it2 != evening.end(); it++, it2++){
            int n1 = *it;
            int n2 = *it2;
            int delta = *it + *it2 - D;
            if(delta > 0)
                sum += delta;
        }
        cout << sum * R << endl;
    }
}