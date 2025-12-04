#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Comb
 * @brief Combinatorics (Factorials, nCr, Inverse).
 * @note STANDALONE: Contains internal modular arithmetic helpers.
 */
namespace Comb {
    using ll = long long;
    const ll MOD = 1e9 + 7;
    
    std::vector<ll> fact, invFact;
    bool _init = false;
    const int MAXN = 1e6 + 5;

    // Internal Helpers
    inline ll mul(ll a, ll b, ll m = MOD) { return (ll)((__int128)a * b % m); }
    
    inline ll extGCD(ll a, ll b, ll &x, ll &y) {
        if (b == 0) { x = 1; y = 0; return a; }
        ll x1, y1;
        ll d = extGCD(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }

    ll inv(ll a, ll m = MOD) {
        ll x, y;
        ll g = extGCD(a, m, x, y);
        if (g != 1) return -1;
        return (x % m + m) % m;
    }

    /**
     * @brief Precomputes factorials. Call this first!
     */
    void init(int n = MAXN) {
        fact.assign(n + 1, 1);
        invFact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = mul(fact[i - 1], i);
        invFact[n] = inv(fact[n]);
        for (int i = n - 1; i >= 0; i--) invFact[i] = mul(invFact[i + 1], i + 1);
        _init = true;
    }

    /**
     * @brief nCr Modulo P.
     */
    ll nCr(int n, int r) {
        if (!_init) init();
        if (r < 0 || r > n) return 0;
        return mul(fact[n], mul(invFact[r], invFact[n - r]));
    }

    /**
     * @brief nCr Direct (No Modulo).
     * @details For small N (<= 62).
     */
    ll nCr_direct(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r;
        ll res = 1;
        for (ll i = 1; i <= r; ++i) {
            res = res * (n - i + 1);
            res /= i;
        }
        return res;
    }
}