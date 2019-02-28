// uva 11906
// algorithm: DFS
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.02.28

/*
    地雷紀錄：
        1. 當 M, N == 0 或 M == N 會多算。
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Node {
    int x;
    int y;
};

int main(){

    int cases;
    cin >> cases;
    for(int bababa = 1; bababa <= cases; bababa++){
        int mapp[105][105] = { 0 };
        int R, C, M, N, waterNum;

        cin >> R >> C >> M >> N >> waterNum;
        // scanf("%d %d %d %d", &R, &C, &M, &N, &waterNum);

        while(waterNum --> 0){
            int x, y;
            cin >> x >> y;
            mapp[x][y] = 2;
        }

        int sumEVEN = 0, sumODD = 0;
        
        stack<Node> ss;
        Node first;
        first.x = 0;
        first.y = 0;
        ss.push(first);

        while(!ss.empty()){
            Node tmp = ss.top();
            ss.pop();
            int count = 0;
            mapp[tmp.x][tmp.y] = 1;
            // cout << "visit: " << tmp.x << "," << tmp.y << endl;
            for(int left = -1; left <= 1; left += 2){
                if(M == 0 && left == 1)
                    continue;
                for(int top = -1; top <= 1; top += 2){
                    int x = tmp.x + (left * M);
                    int y = tmp.y + (top * N);
                    if(N == 0 && top == 1)
                        continue;
                    if(x >= 0 && y >= 0 && x < R && y < C){
                    // cout << "try: " << x << "," << y << endl;
                        if(mapp[x][y] != 2){
                            count++;
                            if(mapp[x][y] == 0){ // not visited
                                mapp[x][y] = 1;
                                Node next;
                                next.x = x;
                                next.y = y;
                                ss.push(next);
                            }
                        }
                    }
                }
            }
            if(M != N){
                for(int left = -1; left <= 1; left += 2){
                    if(N == 0 && left == 1)
                        continue;
                    for(int top = -1; top <= 1; top += 2){
                        int x = tmp.x + (left * N);
                        int y = tmp.y + (top * M);
                        if(M == 0 && top == 1)
                            continue;
                        if(x >= 0 && y >= 0 && x < R && y < C){
                        // cout << "try: " << x << "," << y << endl;
                            if(mapp[x][y] != 2){
                                count++;
                                if(mapp[x][y] == 0){ // not visited
                                    mapp[x][y] = 1;
                                    Node next;
                                    next.x = x;
                                    next.y = y;
                                    ss.push(next);
                                }
                            }
                        }
                    }
                }
            }
            if(count%2)
                sumODD++;
            if(count%2 == 0)
                sumEVEN++;
            // cout << "this is " << ((count%2) ? "odd" : "even" )<< " block" << endl;
        }

        cout << "Case " << bababa << ": " << sumEVEN << " " << sumODD << endl;
    }
}