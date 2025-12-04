#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Util
 * @brief Utilities (CRT, MEX).
 * @note STANDALONE.
 */
namespace Util {
    using ll = long long;

    // Internal helper
    inline ll extGCD(ll a, ll b, ll &x, ll &y) {
        if (b == 0) { x = 1; y = 0; return a; }
        ll x1, y1;
        ll d = extGCD(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }

    /**
     * @brief Chinese Remainder Theorem.
     * @details Solves x = a1 (mod m1), x = a2 (mod m2).
     */
    std::pair<ll, ll> CRT(ll a1, ll m1, ll a2, ll m2) {
        ll p, q;
        ll g = extGCD(m1, m2, p, q);
        if ((a1 - a2) % g != 0) return {-1, -1};
        ll lcm_val = (m1 / g) * m2;
        ll res = (a1 + (__int128)(a2 - a1) / g * p % (m2 / g) * m1) % lcm_val;
        return {(res + lcm_val) % lcm_val, lcm_val};
    }

    /**
     * @brief Minimum Excluded Value (MEX).
     */
    int mex(std::vector<ll> &a) {
        std::set<ll> s(a.begin(), a.end());
        ll m = 0;
        while (s.count(m)) m++;
        return m;
    }
}