#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Bit::Loop
 * @brief Iteration patterns for subsets.
 * @note STANDALONE.
 */
namespace Bit {
    namespace Loop {
        using ll = long long;

        // Next lexicographical bit permutation (Gosper's Hack)
        // Generates the next number with the SAME number of set bits.
        inline ll nextPermutation(ll v) {
            ll t = v | (v - 1);
            return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctzll(v) + 1));
        }

        /*
         * SNIPPET: Iterate over all submasks of a mask 'm'
         * Complexity: O(3^N) total for all masks.
         *
         * for (long long s = m; s > 0; s = (s - 1) & m) {
         * // s is a subset of m
         * }
         */
    }
}