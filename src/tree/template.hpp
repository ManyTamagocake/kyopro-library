#include <bits/stdc++.h>
#include <iterator>
using namespace std;
using ll = long long;

struct Tree{
    struct Edge{
        ll to;
        ll cost;
    };

    ll v;
    ll root;
    vector<vector<Edge>> child;
    vector<Edge> parent;
    vector<ll> deapth;

    vector<vector<ll>> lca_dp;

    Tree(ll n, ll root_input){
        init(n, root_input);
    }

    void init(ll n, ll root_input){
        v = n;
        root = root_input;
        child.assign(n, {});
        parent.assign(n, Edge{-1, -1});
        deapth.assign(n, -1);
        return;
    }

    void add_edge(ll from, ll to, ll cost){
        child[from].push_back(Edge{to, cost});
        parent[to] = Edge{from, cost};
    }

    void dfs_deapth(ll position){
        for (ll i = 0; i < child[position].size(); i++) {
            ll next_position = child[position].size();
            deapth[next_position] = deapth[position] + 1;
            dfs_deapth(next_position);
        }
        return;
    }

    void deapth_init(){
        deapth[root] = 0;
        dfs_deapth(root);
        return;
    }
};
