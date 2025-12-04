/**********************************************************************************************
->                      @author : a_e_kasem
->   "Code is an art — let logic be your ink and syntax your rhythm."
***********************************************************************************************/
//*------------------------------------------------------------------------------------------*//
//                                  ﷽
//                            { وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى }
////*------------------------------------------------------------------------------------------*//

#include <bits/stdc++.h>
using namespace std;

// --- Make all integers long long by default ---
#define int long long

// --- Fast IO ---
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// --- Constants ---
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

/* =========================================================================================
   ULTIMATE NUMBER THEORY LIBRARY (Standalone Modules)
   Usage: Use functions from specific namespaces (e.g., Mod::binpow, Comb::nCr).
   Each namespace is self-contained. You can delete unused namespaces to save space.
   ========================================================================================= */

namespace Basic {
    using ll = long long;
    template<typename T> inline T ceil_div(T a, T b) { return a / b + ((a % b) != 0); }
    inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
    inline ll lcm(ll a, ll b) { if (a == 0 || b == 0) return 0; return (a / gcd(a, b)) * b; }
    inline ll extGCD(ll a, ll b, ll &x, ll &y) {
        if (b == 0) { x = 1; y = 0; return a; }
        ll x1, y1;
        ll d = extGCD(b, a % b, x1, y1);
        x = y1; y = x1 - y1 * (a / b);
        return d;
    }
}

namespace Mod {
    using ll = long long;
    const ll MOD = 1e9 + 7;
    inline ll add(ll a, ll b, ll m = MOD) { return (a + b) % m; }
    inline ll sub(ll a, ll b, ll m = MOD) { return (a - b + m) % m; }
    inline ll mul(ll a, ll b, ll m = MOD) { return (ll)((__int128)a * b % m); }
    ll binpow(ll a, ll b, ll m = MOD) {
        ll res = 1; a %= m;
        while (b > 0) {
            if (b & 1) res = mul(res, a, m);
            a = mul(a, a, m);
            b >>= 1;
        }
        return res;
    }
    inline ll extGCD(ll a, ll b, ll &x, ll &y) { // Helper
        if (b == 0) { x = 1; y = 0; return a; }
        ll x1, y1; ll d = extGCD(b, a % b, x1, y1);
        x = y1; y = x1 - y1 * (a / b); return d;
    }
    ll inv(ll a, ll m = MOD) {
        ll x, y; ll g = extGCD(a, m, x, y);
        if (g != 1) return -1;
        return (x % m + m) % m;
    }
}

namespace Comb {
    using ll = long long;
    const ll MOD = 1e9 + 7;
    std::vector<ll> fact, invFact;
    bool _init = false;
    const int MAXN = 1e6 + 5;
    
    // Internal Helpers for Standalone
    inline ll mul(ll a, ll b, ll m = MOD) { return (ll)((__int128)a * b % m); }
    inline ll extGCD(ll a, ll b, ll &x, ll &y) {
        if (b == 0) { x = 1; y = 0; return a; }
        ll x1, y1; ll d = extGCD(b, a % b, x1, y1);
        x = y1; y = x1 - y1 * (a / b); return d;
    }
    ll inv(ll a, ll m = MOD) {
        ll x, y; ll g = extGCD(a, m, x, y);
        if (g != 1) return -1; return (x % m + m) % m;
    }

    void init(int n = MAXN) {
        fact.assign(n + 1, 1); invFact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = mul(fact[i - 1], i);
        invFact[n] = inv(fact[n]);
        for (int i = n - 1; i >= 0; i--) invFact[i] = mul(invFact[i + 1], i + 1);
        _init = true;
    }
    ll nCr(int n, int r) {
        if (!_init) init();
        if (r < 0 || r > n) return 0;
        return mul(fact[n], mul(invFact[r], invFact[n - r]));
    }
    ll nCr_direct(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r;
        ll res = 1;
        for (ll i = 1; i <= r; ++i) { res = res * (n - i + 1); res /= i; }
        return res;
    }
}

namespace Prime {
    using ll = long long;
    std::vector<int> min_prime, primes, phi, mu;
    bool _init = false;
    void sieve(int n) {
        min_prime.assign(n + 1, 0); phi.assign(n + 1, 0); mu.assign(n + 1, 0);
        phi[1] = 1; mu[1] = 1; primes.clear();
        for (int i = 2; i <= n; ++i) {
            if (min_prime[i] == 0) {
                min_prime[i] = i; primes.push_back(i);
                phi[i] = i - 1; mu[i] = -1;
            }
            for (int p : primes) {
                if (p > min_prime[i] || (ll)i * p > n) break;
                min_prime[i * p] = p;
                if (min_prime[i] == p) { phi[i * p] = phi[i] * p; mu[i * p] = 0; }
                else { phi[i * p] = phi[i] * (p - 1); mu[i * p] = -mu[i]; }
            }
        }
        _init = true;
    }
    std::vector<ll> get_factors(int n) {
        if (!_init) sieve(n > 100000 ? n : 1000000); 
        std::vector<ll> factors;
        while (n > 1) { factors.push_back(min_prime[n]); n /= min_prime[n]; }
        return factors;
    }
}

namespace BigInt {
    using ll = long long;
    inline ll mul(ll a, ll b, ll m) { return (ll)((__int128)a * b % m); }
    inline ll add(ll a, ll b, ll m) { return (a + b) % m; }
    ll binpow(ll a, ll b, ll m) {
        ll res = 1; a %= m;
        while (b > 0) { if (b & 1) res = mul(res, a, m); a = mul(a, a, m); b >>= 1; }
        return res;
    }
    inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }

    bool is_prime(ll n) {
        if (n < 2) return false; if (n == 2 || n == 3) return true; if (n % 2 == 0) return false;
        ll d = n - 1; int s = 0; while ((d & 1) == 0) d >>= 1, s++;
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
    ll pollard_rho(ll n) {
        if (n == 1) return 1; if (n % 2 == 0) return 2;
        ll x = 2, y = 2, d = 1, c = 1;
        auto f = [&](ll x) { return add(mul(x, x, n), c, n); };
        while (d == 1) {
            x = f(x); y = f(f(y)); d = gcd(std::abs(x - y), n);
            if (d == n) { x = 2; y = 2; d = 1; c++; }
        }
        return d;
    }
}

namespace Mat {
    using ll = long long; const int SIZE = 2; const ll MOD = 1e9 + 7;
    inline ll add(ll a, ll b) { return (a + b) % MOD; }
    inline ll mul(ll a, ll b) { return (ll)((__int128)a * b % MOD); }
    struct Matrix {
        ll mat[SIZE][SIZE];
        Matrix() { std::memset(mat, 0, sizeof(mat)); }
        static Matrix identity() {
            Matrix res; for (int i = 0; i < SIZE; i++) res.mat[i][i] = 1; return res;
        }
        Matrix operator*(const Matrix &other) const {
            Matrix res;
            for (int i = 0; i < SIZE; i++)
                for (int k = 0; k < SIZE; k++)
                    for (int j = 0; j < SIZE; j++)
                        res.mat[i][j] = add(res.mat[i][j], mul(mat[i][k], other.mat[k][j]));
            return res;
        }
    };
    Matrix power(Matrix base, ll p) {
        Matrix res = Matrix::identity();
        while (p > 0) { if (p & 1) res = res * base; base = base * base; p >>= 1; }
        return res;
    }
}

namespace Util {
    using ll = long long;
    inline ll extGCD(ll a, ll b, ll &x, ll &y) {
        if (b == 0) { x = 1; y = 0; return a; }
        ll x1, y1; ll d = extGCD(b, a % b, x1, y1);
        x = y1; y = x1 - y1 * (a / b); return d;
    }
    std::pair<ll, ll> CRT(ll a1, ll m1, ll a2, ll m2) {
        ll p, q; ll g = extGCD(m1, m2, p, q);
        if ((a1 - a2) % g != 0) return {-1, -1};
        ll lcm_val = (m1 / g) * m2;
        ll res = (a1 + (__int128)(a2 - a1) / g * p % (m2 / g) * m1) % lcm_val;
        return {(res + lcm_val) % lcm_val, lcm_val};
    }
    int mex(std::vector<ll> &a) {
        std::set<ll> s(a.begin(), a.end());
        ll m = 0; while (s.count(m)) m++; return m;
    }
}

// =========================================================================================

void solve()
{
    // Write your solution here...
    
    // Example: Using Combinatorics
    // int n, r; cin >> n >> r;
    // cout << Comb::nCr(n, r) << endl;
    
    // Example: Using Sieve
    // Prime::sieve(100);
    // cout << Prime::primes.size() << endl;
}

int32_t main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}