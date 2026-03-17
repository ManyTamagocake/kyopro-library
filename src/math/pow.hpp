#ifndef INCLUDED_MAIN
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
#endif

mint mpow(ll base, ll power){
    mint res = 1;
    mint b = base;
    while (power > 0) {
        if (power % 2 == 1){
            res *= b;
        }
        b = b * b;
        power /= 2;
    }
    return res;
}
