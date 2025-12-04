#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace BigInt
 * @brief Algorithms for large numbers (10^18): Miller-Rabin, Pollard's Rho.
 * @note STANDALONE: Includes internal modular arithmetic helpers.
 */
namespace BigInt {
    using ll = long long;

    // --- Internal Helpers ---
    inline ll mul(ll a, ll b, ll m) { return (ll)((__int128)a * b % m); }
    inline ll add(ll a, ll b, ll m) { return (a + b) % m; }
    
    ll binpow(ll a, ll b, ll m) {
        ll res = 1; a %= m;
        while (b > 0) {
            if (b & 1) res = mul(res, a, m);
            a = mul(a, a, m);
            b >>= 1;
        }
        return res;
    }
    
    inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }

    // --- Main Functions ---

    /**
     * @brief Miller-Rabin Primality Test.
     * @return True if prime, False otherwise.
     */
    bool is_prime(ll n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0) return false;
        
        ll d = n - 1; int s = 0;
        while ((d & 1) == 0) d >>= 1, s++;
        
        static const std::vector<ll> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
        for (ll a : bases) {
            if (a % n == 0) continue;
            ll x = binpow(a, d, n);
            if (x == 1 || x == n - 1) continue;
            bool composite = true;
            for (int r = 1; r < s; r++) {
                x = mul(x, x, n);
                if (x == n - 1) { composite = false; break; }
            }
            if (composite) return false;
        }
        return true;
    }

    /**
     * @brief Pollard's Rho Algorithm (Integer Factorization).
     * @return A non-trivial factor of n.
     */
    ll pollard_rho(ll n) {
        if (n == 1) return 1;
        if (n % 2 == 0) return 2;
        ll x = 2, y = 2, d = 1, c = 1;
        auto f = [&](ll x) { return add(mul(x, x, n), c, n); };
        while (d == 1) {
            x = f(x); y = f(f(y));
            d = gcd(std::abs(x - y), n);
            if (d == n) { x = 2; y = 2; d = 1; c++; }
        }
        return d;
    }
}