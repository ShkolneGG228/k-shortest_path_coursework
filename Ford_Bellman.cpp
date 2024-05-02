//https://acmp.ru/index.asp?main=task&id_task=138
#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
vector<vector<pair<int, int>>> G;
vector<int> d;
int main()
{
    int n, m;
    cin >> n >> m;
 
    G.resize(n);
    d.resize(n, 3 * 10e3);
    d[0] = 0;
 
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({ v, w });
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int m = 0; m < G[j].size(); m++) {
                int v = j; int u = G[j][m].first;
                int w = G[j][m].second;
                if (d[v] != 3*10e3 && d[u] > d[v] + w) {
                    d[u] = d[v] + w;
                }
 
            }
        }
    }
    for (int i = 0; i < n; i++) { cout << d[i] << " "; }
}
