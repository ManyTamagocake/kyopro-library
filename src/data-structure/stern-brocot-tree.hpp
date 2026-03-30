#ifndef INCLUDED_MAIN
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#endif

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
