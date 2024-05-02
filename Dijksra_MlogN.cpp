//https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=32&id_topic=54&id_problem=1038
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
 
vector<vector<pair<int, int>>> G, G1;
vector<long long int> dp;
 
int main()
{
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m, s;
    cin >> n >> m >> s;
    dp.resize(n, 2009000999);
    G.resize(n);
    vector<bool> used(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
 
        G[a].push_back({ b, w });
        G[b].push_back({ a, w });
    }
 
 
    dp[s] = 0;
    set<pair<int, int>> q;
    q.insert(make_pair(dp[s], s));
 
    while (!q.empty()) {
        pair<int, int> p = *q.begin();
        int u = p.second;
        used[u] = 1;
        q.erase(q.begin());
 
        for (int i = 0; i < G[u].size(); i++) {
            pair<int, int> p1 = G[u][i];
            int to = p1.first; int w = p1.second;
            if (!used[to]) {
                if (dp[u] + w < dp[to]) {
                    q.erase({ dp[to], to });
                    dp[to] = dp[u] + w;
                    q.insert(make_pair(dp[to], to));
                }
            }
        }
    }
    for (int i = 0; i < n; i++)cout << dp[i] << " ";
}
