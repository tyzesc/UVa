#include <bits/stdc++.h>

using namespace std;

int ax, ay, bx, by, cx, cy;

int main(){
    int cases = 0;
    while(cin >> ax >> ay >> bx >> by >> cx >> cy){
        ax--; ay--; bx--; by--; cx--; cy--;

        int dis[8][8];
        fill(&dis[0][0], &dis[0][0]+sizeof(dis)/sizeof(int), 20);
        dis[ax][ay] = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(ax, ay));
        bool inq[8][8];
        fill(&inq[0][0], &inq[0][0]+sizeof(inq)/sizeof(bool), false);
        inq[ax][ay] = true;

        while(!q.empty()){
            pair<int, int> p = q.front(); q.pop();
            int x = p.first, y = p.second; inq[x][y] = false;

            int directs[8][2] = {{-1,1}, {-1,0}, {-1,-1}, {0,1}, {0,-1}, {1,1}, {1,0}, {1,-1}};
            for(int i = 0; i < 8; i++){
                int nx = x + directs[i][0];
                int ny = y + directs[i][1];
                if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
                    continue;
                
                if(!(nx == cx && ny == cy) && dis[nx][ny] > dis[x][y] + 1){
                    dis[nx][ny] = dis[x][y] + 1;
                    if(!inq[nx][ny]){ q.push(make_pair(nx, ny)); inq[nx][ny] = true; }
                }
            }
        }
        cout << "Case " << ++cases << ": " << dis[bx][by] << '\n';
    }
}