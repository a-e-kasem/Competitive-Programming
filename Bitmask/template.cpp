/**********************************************************************************************
->                      @author : a_e_kasem
->   "Code is an art — let logic be your ink and syntax your rhythm."
***********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

/* =========================================================================================
   ULTIMATE BITMASK LIBRARY (Standalone Modules)
   ========================================================================================= */

namespace Bit {
    using ll = long long;

    // --- Basic Operations ---
    inline bool check(ll mask, int i) { return (mask >> i) & 1; }
    inline ll set(ll mask, int i) { return mask | (1LL << i); }
    inline ll unset(ll mask, int i) { return mask & ~(1LL << i); }
    inline ll toggle(ll mask, int i) { return mask ^ (1LL << i); }
    
    // --- Tricks & Hacks ---
    inline ll getLSB(ll n) { return n & -n; }
    inline bool isPowerOfTwo(ll n) { return n > 0 && (n & (n - 1)) == 0; }
    
    // Trailing Bit Optimization (Replaces loop-based approaches)
    inline ll turnOffLSB(ll n) { return n & (n - 1); }          // Reset first 1 (10110 -> 10100)
    inline ll turnOnRightmostZero(ll n) { return n | (n + 1); } // Set first 0 (10101 -> 10111)
    inline ll fillTrailingZeros(ll n) { return n | (n - 1); }   // Fill 0s after last 1 (10100 -> 10111)
    inline ll clearTrailingOnes(ll n) { return n & (n + 1); }   // Clear 1s after last 0 (10011 -> 10000)

    // --- Builtins (Fast GCC) ---
    inline int popcount(ll n) { return __builtin_popcountll(n); }
    inline int ctz(ll n) { return n ? __builtin_ctzll(n) : 64; } // Trailing Zeros
    inline int clz(ll n) { return n ? __builtin_clzll(n) : 64; } // Leading Zeros
    inline int lastBit(ll n) { return n ? 63 - __builtin_clzll(n) : -1; } // Log2

    // --- Loops Helper ---
    // Gosper's Hack: Next number with same # of set bits
    inline ll nextPermutation(ll v) {
        ll t = v | (v - 1);
        return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctzll(v) + 1));
    }
}

using namespace Bit;

void solve()
{
    // Write your solution here...
    
    // Example:
    // int n = 5; // 101
    // if (check(n, 2)) cout << "Bit 2 is set!" << endl;
    
    // Example 2: Turn off last bit
    // cout << turnOffLSB(n) << endl; // 101 -> 100 (4)
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