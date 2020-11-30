#include <bits/stdc++.h>
#define MAXN (3000 + 10)
#define INF (99999999)
#define VI vector<int>
#define VVI vector<vector<int>>
#define LL long long
using namespace std;

int k[MAXN];
bool b[MAXN];

int main()
{
    int ans = 0;
    int n, tmp;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> k[i];

        tmp = INT_MAX;
        memset(&b[0], 0, sizeof(bool) * n);
        for (int i = 1; i < n; i++)
        {
            int index = abs(k[i] - k[i - 1]);
            if (index >= n)
                break;
            b[index] = true;
        }

        bool flag = false;
        for (int i = 1; i < n; i++)
            if (b[i] == false)
                flag = true;

        if (flag)
            cout << "Not jolly\n";
        else
            cout << "Jolly\n";
    }
}