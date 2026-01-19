// erase this line after completed
#include "graph_template.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> dijkstra(Graph &graph, ll start){
    ll INF = 1LL << 60;
    vector<ll> dist(graph.v, INF);
    dist[start] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        pair<ll, ll> now_node = pq.top();
        pq.pop();
        ll  cur_dist = now_node.first;
        ll cur_pos = now_node.second;
        if (cur_dist > dist[cur_pos]) continue;
        for (ll i = 0; i < graph.adj[cur_pos].size(); ++i) {
            ll next_pos = graph.adj[cur_pos][i].to;
            ll next_dist = cur_dist + graph.adj[cur_pos][i].cost;
            if (next_dist < dist[next_pos]) {
                dist[next_pos] = next_dist;
                pq.push(make_pair(next_dist, next_pos));
            }
        }   
    }
    return dist;
}
