// #define _GLIBCXX_DEBUG

// include and namespace
#include <bits/stdc++.h>
#include <atcoder/all>
#include <memory>
using namespace std;
using namespace atcoder;

// consts
using ll = long long;
using ld = long double;
const ll INF = 1LL<<60;
const ld PI = M_PI;

// macro
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define Yes cout << "Yes\n"
#define No cout << "No\n"

// modulo
using mint = modint998244353;
const ll MOD = 998244353;
// using mint = modint1000000007;
// const ll MOD = 1000000007;

// input and output
template<class T>
void vcin(vector<T> &v){
    for (int i = 0; i < int(v.size()); ++i) cin >> v[i];
    return;
}

template<class T, class U>
void vcin(vector<T> &v, vector<U> &w){
    for (int i = 0; i < int(v.size()); ++i) cin >> v[i] >> w[i];
    return;
}

template<class T> void vcin(vector<vector<T>> &v){
    for (int i = 0; i < int(v.size()); ++i) for (int j = 0; j < int(v[i].size()); ++j) cin >> v[i][j];
    return;
}

template<class T> void vcout(vector<T> &v){
    for (int i = 0; i < int(v.size()); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
    return;
}

template<class T>
void vcout(vector<vector<T>> &v){
    for (int i = 0; i < int(v.size()); ++i) {
        for (int j = 0; j < int(v[i].size()); ++j) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    } 
    return;
}

// max and min
template<class T, class U>
bool chmax(T &a, U b){
    if (a < b) {
        a = b;
        return true;
    }
    else{
        return false;
    }
}

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

void Init(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
}

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

int main(){
    Init();
    ll n,q;cin>>n>>q;
    UnionFind uf(n);
    while(q--){
        ll t,u,v;cin>>t>>u>>v;
        if(t==0){
            uf.merge(u,v);
        }
        else{
            if(uf.same(u,v)){
                cout<<1<<"\n";
            }
            else{
                cout<<0<<"\n";
            }
        }
    }
    return 0;
}
