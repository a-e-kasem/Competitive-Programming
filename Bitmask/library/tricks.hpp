#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Bit::Trick
 * @brief Clever bit manipulation hacks (O(1)).
 * @note STANDALONE.
 */
namespace Bit {
    namespace Trick {
        using ll = long long;

        // --- General ---

        // Check if n is a power of 2 (e.g. 1, 2, 4, 8)
        inline bool isPowerOfTwo(ll n) {
            return n > 0 && (n & (n - 1)) == 0;
        }

        // Get the Least Significant Bit (LSB) only
        // e.g., 10110 -> 00010
        inline ll getLSB(ll n) {
            return n & -n;
        }

        // Get a mask with the lowest k bits set to 1
        // e.g., k=3 -> 111 (binary) = 7
        inline ll getOnes(int k) {
            return (1LL << k) - 1;
        }

        // --- Trailing Bit Manipulations (The Magic) ---

        // Turn off the rightmost set bit (1 -> 0)
        // [Old: resetFirstBitOne]
        // Ex: 10110 -> 10100
        inline ll turnOffLSB(ll n) {
            return n & (n - 1);
        }

        // Turn on the rightmost zero bit (0 -> 1)
        // [Old: setFirstBitZero]
        // Ex: 10101 -> 10111
        inline ll turnOnRightmostZero(ll n) {
            return n | (n + 1);
        }

        // Set all trailing zeros to ones (fill the gap)
        // [Old: changeAllBitsToFirstOne]
        // Ex: 10100 -> 10111
        inline ll fillTrailingZeros(ll n) {
            return n | (n - 1);
        }

        // Set all trailing ones to zeros (strip the layer)
        // [Old: changeAllBitsToFirstZero]
        // Ex: 10011 -> 10000
        inline ll clearTrailingOnes(ll n) {
            return n & (n + 1);
        }
    }
}