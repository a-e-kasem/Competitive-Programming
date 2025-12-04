#  Ultimate Bitmask Library

A standalone C++ library for Bit Manipulation hacks and operations.

##  Modules
| File | Namespace | Description |
| :--- | :--- | :--- |
| [`basic_ops.hpp`](library/basic_ops.hpp) | `Bit::Basic` | Safe Set, Unset, Toggle, Check (64-bit). |
| [`tricks.hpp`](library/tricks.hpp) | `Bit::Trick` | LSB, Power of 2, **Trailing bits optimization**. |
| [`builtins.hpp`](library/builtins.hpp) | `Bit::Builtin` | Wrappers for GCC `__builtin_popcount`, `clz`, `ctz`. |
| [`loops.hpp`](library/loops.hpp) | `Bit::Loop` | Submask iteration logic & Gosper's Hack. |

##  Key Tricks (Optimized)
Instead of using loops to find/change bits, use these O(1) formulas:

| Operation | Function Name | Formula |
| :--- | :--- | :--- |
| Turn off last set bit (1->0) | `turnOffLSB` | `n & (n - 1)` |
| Turn on last zero bit (0->1) | `turnOnRightmostZero` | `n | (n + 1)` |
| Set trailing 0s to 1s | `fillTrailingZeros` | `n | (n - 1)` |
| Set trailing 1s to 0s | `clearTrailingOnes` | `n & (n + 1)` |

##  Submask Loop
To iterate over all submasks of a mask `m` efficiently:

```cpp
for (long long s = m; s > 0; s = (s - 1) & m) {
    // s is a subset of m
}
