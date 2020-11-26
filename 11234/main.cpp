#include <bits/stdc++.h>
#define MAXN (10000+10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

struct Node{
    char value;
    Node* left;
    Node* right;
} node;

int main(){
    int cases; cin >> cases;
    for(int T = 1; T <= cases; T++){
        string s;
        cin >> s;

        Node nodes[MAXN];
        Node* Stack[MAXN];

        int top = 0, cnt = 0;
        for(char d : s){
            nodes[cnt].value = d;
            if(d >= 'a' && d <= 'z'){
                nodes[cnt].left = 0;
                nodes[cnt].right = 0;
                Stack[top++] = &nodes[cnt++];
            }else{
                nodes[cnt].left = Stack[top-1];
                nodes[cnt].right = Stack[top-2];
                Stack[top-2] = &nodes[cnt++];
                top = top - 1;
            }
        }

        string ans = "";
        queue<Node*> q; q.push(Stack[0]);
        while(!q.empty()){
            Node *p = q.front(); q.pop();
            if(p){
                ans += p->value;
                q.push(p->right);
                q.push(p->left);
            }
        }

        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}