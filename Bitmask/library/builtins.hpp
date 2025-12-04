#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Bit::Builtin
 * @brief Fast GCC builtin wrappers for 64-bit integers.
 * @note STANDALONE.
 */
namespace Bit {
    namespace Builtin {
        using ll = long long;

        // Count set bits (Population Count)
        inline int popcount(ll n) {
            return __builtin_popcountll(n);
        }

        // Count Trailing Zeros (zeros after the last 1)
        // e.g., 11000 -> 3. (Safe for n=0 -> returns 64)
        inline int ctz(ll n) {
            return n ? __builtin_ctzll(n) : 64;
        }

        // Count Leading Zeros (zeros before the first 1)
        inline int clz(ll n) {
            return n ? __builtin_clzll(n) : 64;
        }

        // Get the index of the last set bit (Log2 floor)
        // e.g., 8 (1000) -> 3
        inline int lastBit(ll n) {
            return n ? 63 - __builtin_clzll(n) : -1;
        }
    }
}