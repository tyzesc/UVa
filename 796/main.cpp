// uva 796
// algorithm: find brige, DFS
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.10

/*
    地雷紀錄：
        1. 找 Brige，然後排序輸出，這部分看懂還好。
        2. 這題 input 很複雜，pdf 也沒寫到 0 要輸出（一開始以為是結束），踩好多雷。
        3. 參考其他人用 scanf 的 code 都加上 波浪符（~），也沒看懂，但這樣就不會卡迴圈，留個註解有空理解一下。
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

struct Brige{
    int low;
    int high;
};
int N, from, num, to, timer;
vector<int> d, low, pi;
vector<vector<int>> AdjList;
vector<Brige> ans;


void addBrige(int a, int b){
    Brige tmp;
    tmp.low = min(a, b);
    tmp.high = max(a, b);
    for(auto v : ans){
        if(tmp.low == v.low && tmp.high == v.high)
            return;
    }
    ans.push_back(tmp);
}

void DFS_VISIT(int now){
    timer++;
    d[now] = low[now] = timer;
    for(int next : AdjList[now]){
        if(d[next] == 0){
            pi[next] = now;
            DFS_VISIT(next);
            low[now] = min(low[now], low[next]);
            if(low[next] > d[now]){
                addBrige(now, next);
            }
        } else {
            if(next != pi[now])
                low[now] = min(low[now], d[next]);
        }
    }
}

void find_bridges(){
    for(int i = 0; i < N; i++){
        if(d[i] == 0)
            DFS_VISIT(i);
    }
    sort(ans.begin(), ans.end(), [](const Brige &a, const Brige &b){
        if(a.low == b.low)
            return a.high < b.high;
        return a.low < b.low;
    });
    printf("%lu critical links\n", ans.size());
    for(Brige b : ans){
        printf("%d - %d\n", b.low, b.high);
    }
    printf("\n");
}

int main(){
    while(~scanf("%d", &N)){
        // if(!N){
        //     printf("0 critical links\n\n");
        //     continue;
        // };
        AdjList.assign(N, vector<int>());
        d.assign(N, 0);
        low.assign(N, 0);
        pi.assign(N, -1);
        ans.clear();
        timer = 0;
        for(int i = 0; i < N; i++){
            scanf("%d (%d)", &from, &num);
            for(int j = 0; j < num; j++){
                scanf("%d", &to);
                AdjList[from].push_back(to);
            }
        }
        find_bridges();
    }
}