struct UnionFind{
	vector<ll> size, par;

	UnionFind(ll n){
		size.assign(n,1);
		par.assign(n,-1);
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

	bool merge(ll a, ll b){
		if (root(a) == root(b)) return false;
		if (size[root(a)] > size[root(b)]) {
			swap(a,b);
		}
		size[root(b)] += size[root(a)];
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

