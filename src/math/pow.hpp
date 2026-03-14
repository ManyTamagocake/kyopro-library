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
