#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Bit::Basic
 * @brief Fundamental Bitwise Operations.
 * @note STANDALONE: Uses 1LL to ensure 64-bit safety.
 */
namespace Bit {
    namespace Basic {
        using ll = long long;

        // Check if the i-th bit is set (1)
        inline bool check(ll mask, int i) {
            return (mask >> i) & 1;
        }

        // Set the i-th bit to 1
        inline ll set(ll mask, int i) {
            return mask | (1LL << i);
        }

        // Unset the i-th bit (set to 0)
        inline ll unset(ll mask, int i) {
            return mask & ~(1LL << i);
        }

        // Toggle the i-th bit (0 -> 1, 1 -> 0)
        inline ll toggle(ll mask, int i) {
            return mask ^ (1LL << i);
        }

        // Set the i-th bit to value v (0 or 1)
        inline ll setTo(ll mask, int i, int v) {
            return v ? set(mask, i) : unset(mask, i);
        }
    }
}