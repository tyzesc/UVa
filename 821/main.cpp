// uva 821
// algorithm: floyd
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.11

/*
    題意理解：
        給定幾條單向的路徑，算出每一點到其他點的路徑長 的總加總。
        再除以 N(N-1)，N 代表點個數。
    地雷紀錄：

    通靈解法：
        floyd 直接寫，沒啥問題。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int from, to, cases;
    cases = 0;
    while(cin >> from >> to){
        if(!from && !to) continue;
        vector<bool> hasNode;
        hasNode.assign(105, 0);
        vector<vector<int>> paths;
        paths.assign(105, vector<int>());
        for(auto &v : paths) v.assign(105, 0xDEADBEE);

        paths[from][to] = 1;
        hasNode[from] = hasNode[to] = 1;
        while(cin >> from, cin >> to){
            if(!from && !to) break;
            paths[from][to] = 1;
            hasNode[from] = hasNode[to] = 1;
        }

        for(int k = 0; k < paths.size(); k++){
            for(int i = 0; i < paths.size(); i++){
                for(int j = 0; j < paths.size(); j++){
                    paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j]);
                }
            }
        }

        int totalNode = 0;
        int sum = 0;
        for(int i = 0; i < hasNode.size(); i++){
            if(hasNode[i]){
                for(int j = 0; j < hasNode.size(); j++){
                    if(!hasNode[j] || i == j) continue;
                    sum += paths[i][j];
                }
                totalNode++;
            }
        } 

        double ans = (sum*1.0)/(totalNode*(totalNode-1));
        printf("Case %d: average length between pages = %.3f clicks\n", ++cases, ans);
    }
}