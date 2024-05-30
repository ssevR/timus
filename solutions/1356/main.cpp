#pragma GCC optimize("O3")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define ll long long
#define ld long double
#define mp(a, b) make_pair(a, b)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define fi first
#define se second
 
 
const int MOD = 1e9+7; // 998244353; // = (119<<23)+1
const int MX = 2e5+5;
const ll INF = 1e18;
const ld PI = 4*atan((ld)1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
 
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
// ---- is_prime ----
// https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
// 1 IS PRIME 

// test on https://judge.yosupo.jp/problem/primality_test

// it's possible to boost compute time using Montgomery Multiplication


uint64_t mod_pow(uint64_t x, uint64_t y, uint64_t mod) {
    uint64_t ret = 1;
    uint64_t acc = x;
    for( ; y; y >>= 1) {
        if(y & 1) {
            ret = __uint128_t(ret) * acc % mod;
        }
        acc = __uint128_t(acc) * acc % mod;
    }
    return ret;

}

bool miller_rabin(uint64_t n, const std::initializer_list<uint64_t>& as)  {
    return std::all_of(as.begin(), as.end(), [n]( uint64_t a) {
        if (n <= a) { return true; }
        int e = __builtin_ctzll(n - 1);
        uint64_t z = mod_pow(a, (n - 1) >> e, n);
        if (z == 1 || z == n - 1) { return true; }
        while (--e) {
            z = __uint128_t(z) * z % n;
            if (z == 1) { return false; }
            if (z == n - 1) { return true; }
        }
        return false;
    });
}

bool is_prime(uint64_t n) {
    if (n == 2) { return true; }
    if (n % 2 == 0) { return false; }
    if (n < 4759123141) { return miller_rabin(n, { 2, 7, 61 }); }
    return miller_rabin(n, { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 });
}

void solve(int n) {
    if (is_prime(n)) {
        cout << n << '\n';
        return;
    }
    if (is_prime(n - 2)) {
        cout << 2 << ' ' << n - 2 << '\n';
        return;
    }
    if (n % 2 == 1) {
        cout << 3 << ' ';
        solve(n - 3);
        return;
    }
    for (int j = 3; j <= n; ++j) {
        if (is_prime(j) && is_prime(n - j)) {
            cout << j << ' ' << n - j << '\n';
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        solve(n);
    }
}
