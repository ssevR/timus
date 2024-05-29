#pragma GCC optimize("O3")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define ll long long
#define ld long double
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
 
 
int const N = 61;
ll a[N];
ll pr[N];
int n;
ll w;
unordered_map<ll, ll> mp[N];

ll solve(int n, ll w) {
    if (mp[n].count(w)) {
        return mp[n][w];
    }

    if (2 * pr[n] < w || w < 0) {
        return 0;
    }
    if (w == 0) {
        return 1;
    }
    if (n == 1) {
        if (a[0] == w || a[0] * 2 == w) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (n == 0) {
        return 0;
    }

    int f = n;

    while(2 * pr[f - 1] >= w) {
        --f;
    }
    ll res = 0;

    if (f == n) {
        res += solve(f - 1, w - a[f - 1]);
        res += solve(f - 1, w - 2 * a[f - 1]);
        res += solve(f - 1, w);
    }
    else {
        res += solve(f, w - a[f]);
        res += solve(f, w);
    }

    mp[n][w] = res;

    return res;
}

int main() {
    IOS;
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pr[i + 1] = pr[i] + a[i];
    }
    cout << solve(n, w) << '\n';
}
