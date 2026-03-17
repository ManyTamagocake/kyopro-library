#ifndef INCLUDED_MAIN
#include <bits/stdc++.h>
#include "template.hpp"
using namespace std;
using ll = long long;
ll INF = 1LL << 60;
template<class T, class U>
bool chmin(T &a, U b){
    if (a > b) {
        a = b;
        return true;
    }
    else{
        return false;
    }
}
#endif

vector<vector<ll>> warshall_floyd(Graph &graph){
    vector<vector<ll>> dp(graph.v, vector<ll> (graph.v, INF));

    for (ll i = 0; i < graph.v; i++) {
        dp[i][i] = 0;
    }

    for (ll i = 0; i < graph.adj.size(); i++) {
        for (ll j = 0; j < graph.adj[i].size(); j++) {
            chmin(dp[i][graph.adj[i][j].to], graph.adj[i][j].cost);
        }
    }

    for (ll k = 0; k < graph.v; k++) {
        for (ll i = 0; i < graph.v; i++) {
            for (ll j = 0; j < graph.v; j++) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    return dp;
}

