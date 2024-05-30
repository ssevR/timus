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
const ll INF = 1e18;
const ld PI = 4*atan((ld)1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const int N = 20;
 
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
ld dp[1 << N];
ld res[N];

int main() {
    int n;
    cin >> n;

    dp[1] = 1;
    for (int mask = 1; mask < (1 << n) - 1; ++mask) {
        if (dp[mask] == 0) {
            continue;
        }

        int cnt = __builtin_popcount(mask);

        int i = 0;
        while(mask & (1 << i)) ++i;
        i = (i + 1) % n;

        int last = 0;
        for (int j = 0; j < n; ++j) {
            int cur = (i + j) % n;

            if (mask & (1 << cur)) {
                ++last;
            }
            else {
                ++last;
                dp[mask ^ (1 << cur)] += dp[mask] / n * last;

                res[cnt] += dp[mask] * (last * (last - 1) / 2) / n;

                last = 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << setprecision(10) << fixed << res[i] << '\n';
    }
}
