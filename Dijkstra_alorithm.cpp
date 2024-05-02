//https://acmp.ru/index.asp?main=task&id_task=132
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
     
    int n, s, v;
    cin >> n >> s >> v;
    s--; v--;
    vector<vector<int>> G(n, vector<int>(n));
    vector<bool> used(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cin >> G[i][j];
    }
 
    vector<int> dp(n, INT_MAX);
    dp[s] = 0;
    set<pair<int, int>> q;
    q.insert(make_pair(0, s));
 
    while (!q.empty()) {
        pair<int, int> p = *q.begin();
        int u = p.second;
        used[u] = 1;
        q.erase(q.begin());
 
        for (int i = 0; i < n; i++) {
            if (i == u)continue;
            int to = G[u][i];
            if (to >= 0 && !used[i]) {
                if (dp[u] + to < dp[i]) {
                    q.erase({ dp[i], i });
                    dp[i] = dp[u] + to;
                    q.insert(make_pair(dp[i], i));
                }
            }
        }
    }
    if (dp[v] == INT_MAX)cout << -1;
    else cout << dp[v];
}
