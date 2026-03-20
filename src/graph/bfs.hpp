#ifndef INCLUDED_MAIN
#include <bits/stdc++.h>
#include "template.hpp"
using namespace std;
using ll = long long;
#endif

vector<ll> bfs(Graph &graph, ll start){
    ll  INF = 1LL << 60;
    vector<ll> dist(graph.v, INF);
    dist[start] = 0;
    queue<ll> q;
    q.push(start);
    while (!q.empty()) {
        ll pos = q.front();
        q.pop();
        for (Graph::Edge e: graph.adj[pos]) {
            assert(e.cost == 1);
            if (dist[e.to] > dist[pos] + 1) {
                q.push(e.to);
                dist[e.to] = dist[pos] + 1;
            }
        }
    }
    return dist;
}

