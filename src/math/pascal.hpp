#ifndef INCLUDED_MAIN
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#endif

ll max_pascal = 3000;
vector<vector<ll>> pascal(max_pascal, vector<ll> (max_pascal));

void PascalInit(){
    pascal[0][0] = 1;
    for (ll i = 1; i < max_pascal; i++) {
        pascal[i][0] = 1;
        for (int j = 1; j < max_pascal; j++) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }
    return;
}