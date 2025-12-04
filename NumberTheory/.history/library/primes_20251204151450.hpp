#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Prime
 * @brief Linear Sieve, Prime Factorization, Euler Phi, Mobius.
 * @note STANDALONE: No external dependencies.
 */
namespace Prime {
    using ll = long long;
    
    std::vector<int> min_prime, primes, phi, mu;
    bool _init = false;

    /**
     * @brief Linear Sieve (O(N)).
     * @details Populates primes, min_prime, phi, and mu arrays.
     */
    void sieve(int n) {
        min_prime.assign(n + 1, 0);
        phi.assign(n + 1, 0);
        mu.assign(n + 1, 0);
        phi[1] = 1; mu[1] = 1;
        primes.clear();

        for (int i = 2; i <= n; ++i) {
            if (min_prime[i] == 0) {
                min_prime[i] = i;
                primes.push_back(i);
                phi[i] = i - 1;
                mu[i] = -1;
            }
            for (int p : primes) {
                if (p > min_prime[i] || (ll)i * p > n) break;
                min_prime[i * p] = p;
                if (min_prime[i] == p) {
                    phi[i * p] = phi[i] * p;
                    mu[i * p] = 0;
                } else {
                    phi[i * p] = phi[i] * (p - 1);
                    mu[i * p] = -mu[i];
                }
            }
        }
        _init = true;
    }
    
    /**
     * @brief Get Prime Factors.
     * @return vector of factors (e.g. 12 -> 2, 2, 3).
     */
    std::vector<ll> get_factors(int n) {
        if (!_init) sieve(n > 100000 ? n : 1000000); 
        std::vector<ll> factors;
        while (n > 1) {
            factors.push_back(min_prime[n]);
            n /= min_prime[n];
        }
        return factors;
    }
}