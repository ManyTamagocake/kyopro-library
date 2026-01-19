struct Graph{
    struct Edge{
        ll to;
        ll cost;
    };

    ll v;
    vector<vector<Edge>> adj;

    Graph(ll n){
        init(n);
    }

    void init(ll n){
        v = n;
        adj.assign(n, {});
        return;
    }

    void add_edge(ll from, ll to, ll cost){
        adj[from].push_back(Edge{to, cost});
    }

    void add_undirected_edge(ll u, ll v, ll cost){
        add_edge(u, v, cost);
        add_edge(v, u, cost);
    }
};
