#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Mod
 * @brief Modular Arithmetic (Add, Sub, Mul, Power, Inverse).
 * @note STANDALONE: Includes internal GCD logic.
 */
namespace Mod {
    using ll = long long;
    const ll MOD = 1e9 + 7;

    inline ll add(ll a, ll b, ll m = MOD) { return (a + b) % m; }
    inline ll sub(ll a, ll b, ll m = MOD) { return (a - b + m) % m; }
    // Uses __int128 for safety
    inline ll mul(ll a, ll b, ll m = MOD) { return (ll)((__int128)a * b % m); }

    /**
     * @brief Binary Exponentiation (Power).
     * @return (a^b) % m
     */
    ll binpow(ll a, ll b, ll m = MOD) {
        ll res = 1;
        a %= m;
        while (b > 0) {
            if (b & 1) res = mul(res, a, m);
            a = mul(a, a, m);
            b >>= 1;
        }
        return res;
    }

    // Helper for Modular Inverse
    inline ll extGCD(ll a, ll b, ll &x, ll &y) {
        if (b == 0) { x = 1; y = 0; return a; }
        ll x1, y1;
        ll d = extGCD(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }

    /**
     * @brief Modular Inverse.
     * @return x such that (a * x) % m = 1.
     */
    ll inv(ll a, ll m = MOD) {
        ll x, y;
        ll g = extGCD(a, m, x, y);
        if (g != 1) return -1;
        return (x % m + m) % m;
    }
}