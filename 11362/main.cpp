// done dict tree

#include <bits/stdc++.h>
#define CHARN 128
using namespace std;

struct Node {
    bool isEnd;
    Node* nexts[CHARN];
} node;

Node root;

bool add(string s){
    Node* now = &root;
    // cout << "add " << s << endl;
    for(int i = 0; i < s.size(); i++){
        int v = s[i];
        if(now->nexts[v]){
            if(now->nexts[v]->isEnd)
                return false;
        }else{
            now->nexts[v] = new Node();
            if(i == s.size()-1)
                now->nexts[v]->isEnd = true;
        }
        now = now->nexts[v];
    }
    // cout << "here" << root.nexts['4']->isEnd << endl;
    return true;
}

int main(){
    int cases, ans, N;
    cin >> cases;
    while (cases--){
        cin >> N;
        vector<string> v;
        string s;
        while(N--){
            cin >> s;
            v.push_back(s);
        }

        sort(v.begin(), v.end(), [](string a, string b){return a.size() < b.size();});

        root.isEnd = false;
        fill(&root.nexts[0], &root.nexts[0]+sizeof(root.nexts)/sizeof(Node*), nullptr);

        bool flag = false;
        for(string tmp : v){
            if(!add(tmp))
                flag = true;
        }

        cout << (flag?"NO":"YES") << endl;
    }
}