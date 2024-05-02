//https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=32&id_topic=53&id_problem=671
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    vector<int> d(n, INT_MAX);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (i == j)d[i] = x;
            v[i][j] = x;
        }
    }
 
    for (int i = 0; i < n - 1; i++) {
        bool upd = 0;
        for (int j = 0; j < n; j++) {
            for (int m = 0; m < n; m++) {
                if (v[j][m] != 1e5 && d[j] != INT_MAX) {
                    if (d[j] + v[j][m] < d[m]) {
                        d[m] = d[j] + v[j][m];
                        upd = 1;
                    }
                }
            }
        }
        if (!upd)break;
    }
 
    bool upd = 0;
    for (int j = 0; j < n; j++) {
        for (int m = 0; m < n; m++) {
            if (v[j][m] != 1e5 && d[j] != INT_MAX) {
                if (d[j] + v[j][m] < d[m]) {
                    d[m] = d[j] + v[j][m];
                    upd = 1;
                }
            }
        }
    }
 
    if (upd)cout << "YES" << endl;
    else cout << "NO" << endl;
 
}
