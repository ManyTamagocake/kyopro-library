map<ll, ll> factorize(ll n){
	map<ll, ll> res;
	for (ll p=2; p * p <= n; p++) {
		while (n % p == 0) {
			res[p]++;
			n /= p;
		}
	}
	if (n != 1) {
		res[n]++;
	}
	return res;
}

