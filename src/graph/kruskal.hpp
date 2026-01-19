ll kruskal(Graph &graph){
    vector<tuple<ll, ll, ll>> orderd;
    dsu uf(graph.v);
    ll result = 0;

    for (ll i = 0; i < graph.adj.size(); i++) {
        for (ll j = 0; j < graph.adj[i].size(); j++) {
            if (i < graph.adj[i][j].to) {
                orderd.push_back({graph.adj[i][j].cost, i, graph.adj[i][j].to});
            }
        }
    }

    sort(orderd.begin(), orderd.end());
    for (ll i = 0; i < orderd.size() && uf.size(0) < graph.v; i++) {
        ll cost, u, v;
        tie(cost, u, v) = orderd[i];
        if (!uf.same(u, v)) {
            uf.merge(u, v);
            result += cost;
        }
    }

    return result;
}

ll kruskal(Graph &graph, Graph &get){
    vector<tuple<ll, ll, ll>> orderd;
    dsu uf(graph.v);
    ll result = 0;
    get.init(graph.v);

    for (ll i = 0; i < graph.adj.size(); i++) {
        for (ll j = 0; j < graph.adj[i].size(); j++) {
            if (i < graph.adj[i][j].to) {
                orderd.push_back({graph.adj[i][j].cost, i, graph.adj[i][j].to});
            }
        }
    }

    sort(orderd.begin(), orderd.end());
    for (ll i = 0; i < orderd.size() && uf.size(0) < graph.v; i++) {
        ll cost, u, v;
        tie(cost, u, v) = orderd[i];
        if (!uf.same(u, v)) {
            uf.merge(u, v);
            result += cost;
            get.add_undirected_edge(u, v, cost);
        }
    }

    return result;
}

