#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Graph{
    struct Edge{
        ll to;
        ll cost;
    };

    ll v;
    vector<vector<Edge>> g;

    Graph(ll n){
        init(n);
    }

    void init(ll n){
        v = n;
        g.assign(n, {});
        return;
    }

    void add_edge(ll from, ll to, ll cost){
        g[from].push_back(Edge{to, cost});
    }

    void add_undirected_edge(ll u, ll v, ll cost){
        add_edge(u, v, cost);
        add_edge(v, u, cost);
    }
};
