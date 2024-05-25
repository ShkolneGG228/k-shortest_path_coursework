// Yen's_algorithm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<vector<pair<int, int>>> G;
int en = 0;

pair<vector<ll>, vector<int>> Djikstra(vector<int> prefix, set<pair<int, int>> banned_edges, ll weight) {
    set<int> banned_vertex;
    banned_vertex.insert(prefix.begin(), prefix.end());
    vector<int> path;
    int start = prefix.back();
    set<pair<int, int>> s;
    vector<int> pr(G.size()), used(G.size());
    vector<ll>wp(G.size(), LLONG_MAX);
    pr[start] = start;
    s.insert({ weight, start });
    wp[start] = weight;

    while (s.size()) {
        auto a = s.begin();
        int u = a->second;
        used[u] = 1;
        s.erase(a);
        if (u == en)break;

        for (auto &[v, weight_] : G[u]) {
            if (banned_vertex.find(v) != banned_vertex.end())continue;
            if(banned_edges.find({u, v})!=banned_edges.end())continue;
            if (!used[v] && wp[u] + weight_ < wp[v]) {
                s.erase({ wp[v], v });
                wp[v] = wp[u] + weight_;
                pr[v] = u;
                s.insert({ wp[v], v });
            }

        }
    }
    int en1 = en;
    if (used[en1]) {
        while (en1!=start) {
            path.push_back(en1);
            en1 = pr[en1];
        }
        path.push_back(en1);
        reverse(path.begin(), path.end());
    }

    return { wp, path };
}

void yen_algorithm(int u, int v, int k) {
    en = v;
    struct candidat {
        vector<int> prefix;
        set<pair<int, int>> E;
        vector<int> path;
        vector<ll> wp;
        ll W;

        bool operator < (const candidat& c) const {
            return W < c.W;
        }
    };

    vector<pair<ll, vector<int>>> K_path;

    multiset<candidat> cands;

    auto dj = Djikstra({u}, {}, 0);
    cands.insert({ {u}, {}, dj.second,dj.first, dj.first[en]});
    for(int i=0;i<k;i++){
        if (cands.empty())break;
        auto c = cands.begin();
        vector<int> path = c->path;

        vector<int> fullpath = c->prefix;
        for (const auto&el:c->path) {
            if (fullpath.back() != el)fullpath.push_back(el);
        }

        K_path.push_back({ c->W, fullpath });
        //cout << K_path.back().first<<" ";
        vector<int> new_prefix = c->prefix;
        set<pair<int, int>> new_edge = c->E;
        for (int j = 1; j < path.size(); j++) {
            new_edge.insert({ path[j - 1], path[j] });
            auto n = Djikstra(new_prefix, new_edge, c->wp[path[j-1]]);
            //cout << c->wp[path[j - 1]] << " " << n.first[en] << endl;
            if (n.first[en] != LLONG_MAX) {
                cands.insert({ new_prefix, new_edge, n.second, n.first, n.first[en] });
            }
            new_edge.erase({ path[j - 1], path[j] });
            new_prefix.push_back(path[j]);
        }
        cands.erase(c);
    }

    for (int i = 0; i < k; i++) {
        if (i < K_path.size()) {
            cout << K_path[i].first << endl;
            for (const auto& el : K_path[i].second)cout << el+1 << " ";
            cout << endl;
        }
        else cout << -1 << " " ;
    }
    
}

int32_t main()
{
    int n, m ,k, fr, to;
    cin >> n >> m >> k;
    G.resize(n);
    
    /*for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[--a].push_back({ --b, w });
    }*/
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            G[i].push_back({ j, i+j+2 });
        }
    }

    fr = 0;
    to = n-1;
    yen_algorithm(fr, to, k);

}