// $%D%$.$%M%$.$%Y%$
// $%h%$:$%m%$:$%s%$

#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define ll long long
#define ld long double
#define rep(i,a,n) for (int i=(int)(a);i<(int)(n);i++)
#define per(i,a,n) for (int i=(int)(n-1);i>=(int)(a);i--)
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
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};


template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int k, n, m;

int f(int x, int y, int t) {
    if (!(x >= 0 && x < n  && y >= 0 && y < m)) {
        return 0;
    }
    if (t == 0) {
        return y + k - 1 < m;
    }
    else {
        return x + k - 1 < n;
    }
}

int main() {
    int l;
    cin >> n >> m >> l;
    vector<pair<pii, int> > v, h;
    for (int i = 0; i < l; ++i) {
        int x, y, len;
        char t;
        cin >> x >> y >> len >> t;
        --x, --y;
        if (t == 'V') {
            v.push_back({{x, y}, len});
        }
        else {
            h.push_back({{x, y}, len});
        }
    }
    cin >> k;
    ll ans = 1ll * n * (m - 1) + 1ll * (n - 1) * m;
    set<pii> s_v, s_h;

    for (auto cur : v) {
        for (int x = cur.first.first - 1; x <= cur.first.first + 1; ++x) {
            for (int y = cur.first.second - k; y <= cur.first.second + cur.second; ++y) {
                if (f(x, y, 0)) {
                    s_v.insert({x, y});
                }
            }
        }
        
        for (int x = cur.first.first - k; x <= cur.first.first + 1; ++x) {
            for (int y = cur.first.second - 1; y <= cur.first.second + cur.second; ++y) {
                if (f(x, y, 1)) {
                    s_h.insert({x, y});
                }
            }
        }
    }

    for (auto cur : h) {
        for (int x = cur.first.first - k; x <= cur.first.first + cur.second; ++x) {
            for (int y = cur.first.second - 1; y <= cur.first.second + 1; ++y) {
                if (f(x, y, 1)) {
                    s_h.insert({x, y});
                }
            }
        }

        for (int x = cur.first.first - 1; x <= cur.first.first + cur.second; ++x) {
            for (int y = cur.first.second - k; y <= cur.first.second + 1; ++y) {
                if (f(x, y, 0)) {
                    s_v.insert({x, y});
                }
            }
        }
    }

    cout << ans - s_v.size() - s_h.size() << '\n';

    return 0;
}
