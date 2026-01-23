vector<bool> eratosthenes(ll n){
    vector<bool> is_prime(n+1,true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (ll d = 2; d <= n; d++) {
         for (ll i = d * 2; i <= n; i += d) {
            is_prime[i] = false;
        }
    }
    return is_prime;
}
