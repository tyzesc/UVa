// uva 481
// algorithm: DP, LIS
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.04.29

/*
    地雷紀錄：
        答案是要找到最新一次 LIS，這卡超久。
        最後是多開 vector 來存 level，最後倒序搜尋前一個。
    通靈解法：
        用 binary-search 將 O(n^2) 降至 O(nlogn)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<int> LIS, num, level;

int main(){
    int input;
    int length = 1;
    cin >> input;
    num.push_back(input);
    level.push_back(0);
    LIS.push_back(input);
    while(cin >> input){
        num.push_back(input);
        level.push_back(0);
        int position = lower_bound(LIS.begin(), LIS.end(), input) - LIS.begin();
        if(position >= length){
            LIS.push_back(input);
            level.back() = length++;
        }else{
            level.back() = position;
            LIS[position] = input;
        }
    }
    cout << length << endl << "-" << endl;
    stack<int> ss;
    int now = length - 1;
    for(int i = num.size() - 1; i >= 0, now >= 0; i--){
        if(level[i] == now){
            ss.push(num[i]);
            now--;
        }
    }
    while(!ss.empty()){
        int tmp = ss.top(); ss.pop();
        cout << tmp << endl;
    }
}