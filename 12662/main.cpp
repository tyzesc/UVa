#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int N, M, in;
string names[MAXN];
vector<int> v;

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> names[i];
        if(names[i] != "?")
            v.push_back(i);
    }
    cin >> M;
    while(M--){
        cin >> in;
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), in);
        int a = abs(in - (*(it-1))); if(a == in) a = INT_MAX;
        int b = abs(in - (*it)); if(b == in) b = INT_MAX;
            if(a == b){
                cout << "middle of " << names[*(it-1)] << " and " << names[(*it)] << endl;
            }else if(b == 0){
                cout << names[*(it)] << endl;
            }else if(a == 0){
                cout << names[*(it-1)] << endl;
            }else{
                for(int i = 0; i < min(a, b); i++)
                    cout << (a>b?"left":"right") << " of ";
                cout << names[*(a>b?it:it-1)] << endl;
            }
    }
}