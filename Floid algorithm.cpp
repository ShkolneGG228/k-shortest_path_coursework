//https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=32&id_topic=52&id_problem=667
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cin >> m[i][j];
    }
 
    for (int k = 0; k < n ; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << '\n';
    }
}
