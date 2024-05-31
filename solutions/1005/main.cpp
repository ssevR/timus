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
 
 
int main() {
    int n;
    cin >> n;
    int w[20];
    ll su = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        su += w[i];
    }

    ll res = su;
    for (int i = 0; i < (1 << n); ++i) {
        ll cur = 0;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j)) {
                cur += w[j];
            }
        res = min(res, abs(su - 2 * cur));

    }
    cout << res << '\n';
}
