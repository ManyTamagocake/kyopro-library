#ifndef INCLUDED_MAIN
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#endif

struct Graph{
    struct Edge{
        ll to;
        ll cost;
    };

    ll v;
    vector<vector<Edge>> adj;

    ll root = -1;
    vector<vector<Edge>> child;
    vector<Edge> parent;

    Graph(ll n){
        init(n);
    }

    void treeinit(ll root_input){
        root = root_input;
        child.assign(v, {});
        parent.assign(v, Edge{-1, 0});
        vector<bool> visited(v, false);
        queue<ll> q;
        q.push(root);
        visited[root] = true;
        while(!q.empty()){
            ll u = q.front();
            q.pop();
            for(auto e : adj[u]){
                if(visited[e.to]) continue;
                visited[e.to] = true;
                parent[e.to] = Edge{u, e.cost};
                child[u].push_back(e);
                q.push(e.to);
            }
        }
        return;
    }

    void init(ll n){
        v = n;
        adj.assign(n, {});
        return;
    }

    void add_edge(ll from, ll to, ll cost){
        adj[from].push_back(Edge{to, cost});
        return;
    }

    void add_undirected_edge(ll u, ll v, ll cost){
        add_edge(u, v, cost);
        add_edge(v, u, cost);
        return;
    }
};
