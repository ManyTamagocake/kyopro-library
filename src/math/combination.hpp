#ifndef INCLUDED_MAIN
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
ll MOD = 998244353;
#endif


const int COM_MAX = 300000;
vector<mint> fac(COM_MAX), finv(COM_MAX), inv(COM_MAX);

void COMinit(){
    fac[0] = 1;
    fac[1] = 1;
    finv[0] = 1;
    finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < COM_MAX; i++) {
        fac[i] = fac[i-1] * i;
        inv[i] = MOD - inv[MOD % i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
    return;
}

mint COM(ll n, ll k){
    if (n < k) {
        return 0;
    }
    if (n < 0 || k < 0) {
        return 0;
    }
    return fac[n] * finv[k] * finv[n - k];
}

