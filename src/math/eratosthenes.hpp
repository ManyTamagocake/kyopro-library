#ifndef INCLUDED_MAIN
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#endif

vector<bool> eratosthenes(ll n){
    vector<bool> is_prime(n+1,true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (ll d = 2; d * d <= n; d++) {
        if (!is_prime[d]) continue;
         for (ll i = d * d; i <= n; i += d) {
            is_prime[i] = false;
        }
    }
    return is_prime;
}
