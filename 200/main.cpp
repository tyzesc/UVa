// uva 200
// algorithm: topological sort, DFS
// author: Yen-Cheng, Zhang (Tyze, tyzesc)
// date: 2019.02.28

/*
    地雷紀錄：
        1. 最後輸出要多個換行，沒結果要 NO。都加 flag 解決。
        2. 字串特殊的排序，常用拓譜。依照題目要求調整權重。
*/
#include <iostream>
#include <queue>
#include <string>
#include <math.h>
using namespace std;

string now;
string last;
bool flag_one = true;
bool paths[26][26];
bool used[26] = {false};
bool visited[26] = {false};

void dfs(int index){
	visited[index] = true;
	for(int i = 0; i < 26; i++){
		if(paths[i][index] && !visited[i]){
			dfs(i);
		}
	}
	cout << (char)('A' + index);
}
int main(){
	cin >> now;
	while(last = now, cin >> now, now != "#"){
		flag_one = false;
		for(int i = 0; i < min(now.length(), last.length()); i++){
			int l = last[i] - 'A';
			int n = now[i] - 'A';
			used[l] = used[n] = true;
			if(now[i] != last[i]){
				paths[ l ][ n ] = true;
				break;
			}
		}
	}

	if(flag_one){
		cout << now;
	}else{
		for(int index = 0; index < 26; index++){
			if( used[index] && !visited[index] ) // if index charater is used, and not be visited 
				dfs(index);
		}
	}
	cout << endl;
	return 0;
}