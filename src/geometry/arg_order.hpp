struct Vec{
    ll x,y;
    ll sign;
    ll g;
    Vec(): x(0), y(0), sign(0) {}
    Vec(ll inx, ll iny){
        if (iny > 0 || (iny == 0 && inx > 0)) {
            sign = -1;
        }
        else {
            sign = 1;
        }
        g = abs(__gcd(inx, iny));
        x = inx / g;
        y= iny / g;
    }
};

auto operator<(Vec a, Vec b){
    if (a.sign != b.sign) {
        return a.sign < b.sign;
    }
    else {
        return b.x*a.y<a.x*b.y;
    }
}

auto operator==(Vec a, Vec b){
    return a.x == b.x && a.y == b.y;
}

