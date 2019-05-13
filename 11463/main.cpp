// uva 11463
// algorithm: floyd
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.05.14

/*
    題意理解：
        要炸毀軍事要地，需經過每一個點。
    地雷紀錄：

    通靈解法：
        Floyd 直接掃過，然後找最長總路徑。
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int T, N, P, x, y;
    cin >> T;
    for(int cases = 1; cases <= T; cases++){
        vector<vector<int> > path;
        cin >> N >> P;
        path.assign(N, vector<int>());
        for(auto &v : path)
            v.assign(N, 0xDEADBEE);
        for(int i = 0; i < N; i++){
            path[i][i] = 0;
        }

        while(P--){
            cin >> x >> y;
            path[x][y] = path[y][x] = 1;
        }
        cin >> x >> y;

        for(int k = 0; k < N; k++)
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    path[i][j] = min(path[i][j], path[i][k] + path[k][j]);

        int ans = 0;
        for(int k = 0; k < N; k++){
            ans = max(ans, path[x][k] + path[k][y]);
        }
        cout << "Case " << cases << ": " << ans << endl;
    }
}
