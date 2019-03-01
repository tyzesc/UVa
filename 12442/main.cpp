// uva 12442
// algorithm: DFS
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.03.01

/*
    地雷紀錄：
        1. 嘗試用累加的方式，當遇到之前走完的會 return 之前算好的。
           但當有環時，之前算好的會不正確 如 1->2 2->1。
           會導致 counts[1] == 2, counts[2] == 1 的情況。
           整個環的值不會相同，所以改成用每一點遍歷。
        2. 如上，直接做會超時。所以增加 counts[i] == 0 時才做。
           因為當 counts 有值時，i 本身就有可能是 maxIndex 或本身是最大的的 descendant。
           以減少 DFS 的次數。
*/
#include <iostream>

using namespace std;

int task, cases;
int maxVal, maxIndex;

int dfs(int now, int visited[50005], int counts[50005], int paths[50005]){
    if(visited[now])
        return 0;
    visited[now] = true;
    int cnt = 1;
    int next = paths[now];
    // cout << "DFS: " << now << " next is " << next << next && !visited[next] << endl;
    if(next && !visited[next]){
        cnt = (1+dfs(next, visited, counts, paths));
        visited[next] = false;
    }
    counts[now] = cnt;
    return cnt;
}

int main(int argc, char* argv[]){
    cin >> task;
    for(int index = 1; index <= task; index++){
        int visited[50005] = { 0 };
        int counts[50005] = { 0 };
        int paths[50005] = { 0 };
        maxVal = maxIndex = 0;
        cin >> cases;
        int tmp = cases;
        while(tmp --> 0){
            int from, to;
            cin >> from >> to;
            paths[from] = to;
        }
        for(int i = 1; i <= cases; i++){
            visited[i-1] = false;
            if(counts[i] == 0){
                int val = dfs(i, visited, counts, paths);
                // cout << "run on : " << i << " ,value: " << val << endl;;
                if(val > maxVal){
                    maxIndex = i;
                    maxVal = val;
                }
            }
        }
        cout << "Case " << index << ": " << maxIndex << endl;
    }
}