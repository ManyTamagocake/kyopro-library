#ifndef INCLUDED_MAIN
#include <bits/stdc++.h>
#include "template.hpp"
#include "bfs.hpp"
using namespace std;
using ll = long long;
#endif

ll treediameter(Graph &graph){
    vector<ll> d1 = bfs(graph, 0);
    ll longest_node = -1;
    ll longest_cost = -1;
    for (long i = 0; i < graph.v; ++i) {
        if (d1[i] > longest_cost) {
            longest_node = i;
            longest_cost = d1[i];
        }
    }
    vector<ll>d2 = bfs(graph, longest_node);
    ll result = -1;
    for (long i = 0; i < graph.v; ++i) {
        if (d2[i] > result) {
            result = d2[i];
        }
    }
    return result;
}

