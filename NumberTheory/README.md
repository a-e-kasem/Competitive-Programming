# Ultimate Number Theory Library

A high-performance, **standalone**, and modular C++ library designed for **Competitive Programming** (Codeforces, AtCoder, ICPC).

## Philosophy
**Zero Dependencies:** Unlike other libraries, every file in this repository is **self-contained**. 
You can copy just `combinatorics.hpp` into your solution without needing to copy `modular.hpp` or `basic_math.hpp`. This makes it perfect for quick Copy-Paste during contests.

## Modules overview

| File | Namespace | Description |
| :--- | :--- | :--- |
| [`basic_math.hpp`](library/basic_math.hpp) | `Basic` | Safe Ceil Division, GCD, LCM, Extended Euclidean. |
| [`modular.hpp`](library/modular.hpp) | `Mod` | Modular Add/Sub/Mul, Modular Inverse, Binary Exponentiation. |
| [`primes.hpp`](library/primes.hpp) | `Prime` | Linear Sieve (O(N)), Prime Factorization, Euler Phi, Mobius Function. |
| [`combinatorics.hpp`](library/combinatorics.hpp) | `Comb` | nCr (Modulo & Direct), Precomputed Factorials. |
| [`big_int.hpp`](library/big_int.hpp) | `BigInt` | **Miller-Rabin** (Primality Test) & **Pollard's Rho** (Factorization) for 64-bit integers (~10^18). |
| [`matrix.hpp`](library/matrix.hpp) | `Mat` | Matrix Exponentiation for solving Linear Recurrences. |
| [`utils.hpp`](library/utils.hpp) | `Util` | Chinese Remainder Theorem (CRT), MEX. |

## Usage in Contests

Since every file is standalone, simply open the file you need and copy its content into your `main.cpp` before the `solve()` function.

### Example 1: Calculating nCr
If you need combinations, just copy `library/combinatorics.hpp`:

```cpp
// [Paste content of combinatorics.hpp here]

using namespace Comb;

void solve() {
    int n, r; 
    cin >> n >> r;
    // Calculates nCr % 1e9+7 efficiently
    cout << nCr(n, r) << endl;
}