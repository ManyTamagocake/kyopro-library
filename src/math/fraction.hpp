#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fraction{
    ll numerator;
    ll denominator;

    Fraction(ll input_numerator, ll input_denominator){
        if (input_denominator < 0) {
            input_numerator *= -1;
            input_denominator *= -1;
        }
        ll g = __gcd(abs(input_numerator), input_denominator);
        numerator = input_numerator / g;
        denominator = input_denominator / g;
    }

    Fraction(): numerator(0), denominator(1) {}

    auto operator<(Fraction other) const {
        return (__int128_t)numerator * other.denominator < (__int128_t)other.numerator * denominator;
    }

    auto operator==(Fraction other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
};
