#define INCLUDED_MAIN
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef INCLUDED_MAIN
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#endif

struct PrefixSumHalfOpen {
    vector<ll> sum;

    PrefixSumHalfOpen(const vector<ll> &vec) {
        sum.resize(vec.size());
        for (int i = 0; i < vec.size(); ++i) {
            sum[i] = vec[i];
        }
        for (int i = 1; i < vec.size(); ++i) {
            sum[i] += sum[i - 1];
        }
    }

    ll prod(int l, int r) {
        assert(0 <= l && l <= r && r <= sum.size());
        if (l == r) {
            return 0;
        }
        else if (l == 0) {
            return sum[r - 1];
        }
        else {
            return sum[r - 1] - sum[l - 1];
        }
    }
};

struct PrefixSumClosed {
    vector<ll> sum;

    PrefixSumClosed(const vector<ll> &vec) {
        sum.resize(vec.size());
        for (int i = 0; i < vec.size(); ++i) {
            sum[i] = vec[i];
        }
        for (int i = 1; i < vec.size(); ++i) {
            sum[i] += sum[i - 1];
        }
    }

    ll prod(int l, int r) {
        assert(0 <= l && l <= r && r < sum.size());
        if (l == 0) {
            return sum[r];
        }
        else {
            return sum[r] - sum[l - 1];
        }
    }
};

int main(){
    ll n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    PrefixSumHalfOpen s(a);

    ll l, r;
    while (q--) {
        cin >> l >> r;
        cout << s.prod(l, r) << "\n";
    }
}