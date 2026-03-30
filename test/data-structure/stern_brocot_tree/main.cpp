// https://judge.yosupo.jp/problem/stern_brocot_tree

// #define _GLIBCXX_DEBUG

#define INCLUDED_MAIN

// include and namespace
#include <bits/stdc++.h>
#include <atcoder/all>
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

namespace sbt {
    pair<ll, ll> get_fraction(ll p, ll q, ll r, ll s) {
        return make_pair(p + r, q + s);
    }

    pair<ll, ll> get_fraction(tuple<ll, ll, ll, ll> info) {
        ll p, q, r, s;
        tie(p, q, r, s) = info;
        return make_pair(p + r, q + s);
    }

    vector<pair<char, ll>> encode_path(ll a, ll b){
        vector<pair<char, ll>> res;

        while (a != b) {
            if (a > b) {
                ll q = a / b;
                if (a % b == 0) {
                    q--;
                }
                res.push_back(make_pair('R', q));
                a -= b * q;
            }
            else {
                ll q = b / a;
                if (b % a == 0) {
                    q--;
                }
                res.push_back(make_pair('L', q));
                b -= a * q;
            }
        }

        return res;
    }

    tuple<ll, ll, ll, ll> decode_path(const vector<char> &c, const vector<ll> &n){
        pair<ll, ll> res;

        ll p = 0, q = 1, r = 1, s = 0;

        for (ll i = 0; i < c.size(); ++i) {
            if (c[i] == 'L') {
                r = n[i] * p + r;
                s = n[i] * q + s;
            }
            else{
                p = p + n[i] * r;
                q = q + n[i] * s;
            }
        }

        return make_tuple(p, q, r, s);
    }

    tuple<ll, ll, ll, ll> decode_path(const vector<pair<char, ll>> &code) {
        vector<char> c(code.size());
        vector<ll> n(code.size());
        for (ll i = 0; i < code.size(); ++i) {
            c[i] = code[i].first;
            n[i] = code[i].second;
        }

        return decode_path(c, n);
    }

    pair<ll, ll> lca(ll a, ll b, ll c, ll d) {
        vector<pair<char, ll>> code_ab = encode_path(a, b);
        vector<pair<char, ll>> code_cd = encode_path(c, d);

        vector<pair<char, ll>> prefix_same;
        for (ll i = 0; i < min(code_ab.size(), code_cd.size()); ++i) {
            if (code_ab[i].first != code_cd[i].first) break;
            if (code_ab[i].second != code_cd[i].second) {
                prefix_same.push_back(make_pair(code_ab[i].first, min(code_ab[i].second, code_cd[i].second)));
                break;
            }
            else{
                prefix_same.push_back(code_ab[i]);
            }
        }

        return get_fraction(decode_path(prefix_same));
    }

    pair<ll, ll> ancestor(ll k, ll a, ll b) {
        vector<pair<char, ll>> code = encode_path(a, b);

        vector<pair<char, ll>> ancestor_code;
        for (ll i = 0; i < code.size(); ++i) {
            if (code[i].second >= k) {
                ancestor_code.push_back(make_pair(code[i].first, k));
                k = 0;
                break;
            }
            else {
                ancestor_code.push_back(code[i]);
                k -= code[i].second;
            }
        }

        if (k > 0) {
            return make_pair(-1, -1);
        }
        else{
            return get_fraction(decode_path(ancestor_code));
        }
    }

    pair<pair<ll, ll>, pair<ll, ll>> range(ll a, ll b) {
        vector<pair<char, ll>> code = encode_path(a, b);
        ll p, q, r, s;
        tie(p, q, r, s) = decode_path(code);

        return make_pair(make_pair(p, q), make_pair(r, s));
    }
}  // namespace sbt

void solve_encode_path(){
    ll a, b;
    cin >> a >> b;

    vector<pair<char, ll>> res = sbt::encode_path(a, b);

    cout << res.size() << " ";
    for (auto p: res) {
        cout << p.first << " " << p.second << " ";
    }
    cout << "\n";

    return;
}

void solve_decode_path(){
    ll k;
    cin >> k;

    vector<char>c(k);
    vector<ll>n(k);
    for (ll i = 0; i < k; i++) {
        cin >> c[i] >> n[i];
    }

    pair<ll, ll> res;
    res = sbt::get_fraction(sbt::decode_path(c, n));

    cout << res.first << " " << res.second << "\n";

    return;
}

void solve_lca(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    pair<ll, ll> res = sbt::lca(a, b, c, d);

    cout << res.first << " " << res.second << "\n";

    return;
}

void solve_ancestor(){
    ll k, a, b;
    cin >> k >> a >> b;

    pair<ll, ll> res = sbt::ancestor(k, a, b);

    if (res == make_pair(-1LL, -1LL)) {
        cout << -1 << "\n";
    }
    else{
        cout << res.first << " " << res.second << "\n";
    }

    return;
}

void solve_range(){
    ll a, b;
    cin >> a >> b;

    pair<pair<ll, ll>, pair<ll, ll>> res = sbt::range(a, b);

    cout << res.first.first << " " << res.first.second << " " << res.second.first << " " << res.second.second << "\n";

    return;
}

int main(){
    Init();

    ll t;
    cin >> t;

    while (t--) {
        string problem_type;
        cin >> problem_type;

        if (problem_type == "ENCODE_PATH") {
            solve_encode_path();
        }
        else if (problem_type == "DECODE_PATH") {
            solve_decode_path();
        }
        else if (problem_type == "LCA") {
            solve_lca();
        }
        else if (problem_type == "ANCESTOR") {
            solve_ancestor();
        }
        else if (problem_type == "RANGE") {
            solve_range();
        }
        else {
            assert(1);
        }
    }

    return 0;
}
