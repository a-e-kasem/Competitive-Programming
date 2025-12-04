namespace Basic {
    using ll = long long;

    template<typename T> 
    inline T ceil_div(T a, T b) { return a / b + ((a % b) != 0); }

    inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
    
    inline ll lcm(ll a, ll b) { if (a == 0 || b == 0) return 0; return (a / gcd(a, b)) * b; }

    // Returns g = gcd(a, b); finds x, y such that d = ax + by
    inline ll extGCD(ll a, ll b, ll &x, ll &y) {
        if (b == 0) { x = 1; y = 0; return a; }
        ll x1, y1;
        ll d = extGCD(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }
}
