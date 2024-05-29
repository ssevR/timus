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
const int N = 101;
 
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int dp[N][N * N];

int main() {
    int n, k;
    cin >> n >> k;

    dp[1][0] = 1;
    dp[2][0] = 1;

    for (int i = 3; i <= n; ++i) {
        dp[i][i * (i - 1) / 2] = i;
        for (int j = 1; j < i; ++j) {
            if (j == i - 2) {
                continue;
            }
            for (int f = 0; f <= j * (j - 1) / 2; ++f) {
                if (dp[j][f]) {
                    dp[i][f + (i - j) * (i - j - 1) / 2] = i - j;
                }
            }
        }
    }
    k = n * (n - 1) / 2 - k;
    if (!dp[n][k]) {
        cout << -1 << '\n';
        return 0;
    }

    while(n) {
        for (int i = n - dp[n][k] + 1; i < n; ++i) {
            cout << i << ' ' << i + 1 << '\n';
        }
        if (dp[n][k] != 1) {
            cout << n << ' ' << n - dp[n][k] + 1 << '\n';
        }
        if (n - dp[n][k] + 1 > 1) {
            cout << n - dp[n][k] << ' ' << n - dp[n][k] + 1 << '\n';
        }

        int cnt = dp[n][k];
        k -= cnt * (cnt - 1) / 2;
        n -= cnt;
    }

}
