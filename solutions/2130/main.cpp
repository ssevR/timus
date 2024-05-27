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
const ll MX = 1000000000000;
const ll INF = 1e18;
const ld PI = 4*atan((ld)1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
 
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main() {
    IOS;

    int n;
    cin >> n;
    vector<pair<ll, int> > g, b;
    ll res = 1;

    int flag = 0;

    int r = n;

    g.push_back({1, -1});
    for (int i = 0; i < n; ++i) {
        int d, t;
        cin >> d >> t;

        if (t == 1) {
            if (!flag) {
                ll tmp = lcm(res, (ll)d);
                if (tmp <= MX) {
                    res = tmp;
                }
                else {
                    flag = 1;
                    r = i;
                }
            }
            g.push_back({res, i});
        }
        else {
            b.push_back({d, i});
        }
    }
    int f = g.size() - 1;

    for (int i = 0; i < b.size(); ++i) {
        if (b[i].fi == 1) {
            r = min(r, b[i].se);
            continue;
        }
        else if (g[f].fi % b[i].fi) {
            continue;
        }

        while(g[f - 1].fi % b[i].fi == 0) {
            --f;
        }
        r = min(r, max(b[i].se, g[f].se));
    }

    res = 1;
    for (int i = 0; i < g.size(); ++i) {
        if (g[i].se < r) {
            res = g[i].fi;
        }
    }

    for (int i = 0; i < r; ++i) {
        cout << res << '\n';
    }

    for (int i = r; i < n; ++i) {
        cout << -1 << '\n';
    }

    return 0;
}

