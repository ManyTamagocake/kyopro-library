#ifndef INCLUDED_MAIN
#include <bits/stdc++.h>
#include "template.hpp"
using namespace std;
using ll = long long;
#endif

vector<ll> bfs01(Graph &graph, ll start){
    ll INF = 1LL << 60;
    vector<ll> dist(graph.v, INF);

    dist[start] = 0;
    deque<ll>q;
    q.push_back(start);

    while (!q.empty()) {
        ll pos = q.front();
        q.pop_front();
        for (auto e: graph.adj[pos]) {
            if (dist[e.to] > dist[pos] + e.cost) {
                dist[e.to] = dist[pos] + e.cost;
                if (e.cost==0) {
                    q.push_front(e.to);
                }
                else {
                    q.push_back(e.to);
                }
            }
        }
    }
    return dist;
}

