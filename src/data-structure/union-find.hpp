#ifndef INCLUDED_MAIN
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#endif

struct UnionFind{
	vector<ll> size, par;
    vector<ll> edge;

	UnionFind(ll n){
		size.assign(n,1);
		par.assign(n,-1);
        edge.assign(n,0);
	}

	ll root(ll a){
		if (par[a] == -1) {
			return a;
		}
		else {
			return par[a] = root(par[a]);
		}
	}

	ll get_size(ll v){
		return size[root(v)];
	}

    ll get_edge(ll v){
        return edge[root(v)];
    }

	bool merge(ll a, ll b){
		if (root(a) == root(b)){
            edge[root(a)]++;
            return false;
        }
		if (size[root(a)] > size[root(b)]) {
			swap(a,b);
		}
		size[root(b)] += size[root(a)];
        edge[root(b)] += edge[root(a)] + 1;
		par[root(a)] = root(b);
		return true;
	}
     
	bool same(ll a, ll b){
		if (root(a) == root(b)) {
			return true;
		}
		else {
			return false;
		}
	}
};

