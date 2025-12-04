#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Mat
 * @brief Matrix Exponentiation.
 * @note STANDALONE: Internal modular arithmetic.
 */
namespace Mat {
    using ll = long long;
    const int SIZE = 2; // Size of Matrix
    const ll MOD = 1e9 + 7;

    // Internal Helpers
    inline ll add(ll a, ll b) { return (a + b) % MOD; }
    inline ll mul(ll a, ll b) { return (ll)((__int128)a * b % MOD); }

    struct Matrix {
        ll mat[SIZE][SIZE];
        Matrix() { std::memset(mat, 0, sizeof(mat)); }
        
        static Matrix identity() {
            Matrix res;
            for (int i = 0; i < SIZE; i++) res.mat[i][i] = 1;
            return res;
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

    /**
     * @brief Matrix Power (base^p).
     * @details Solves linear recurrences efficiently.
     */
    Matrix power(Matrix base, ll p) {
        Matrix res = Matrix::identity();
        while (p > 0) {
            if (p & 1) res = res * base;
            base = base * base;
            p >>= 1;
        }
        return res;
    }
}