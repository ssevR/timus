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
    pii xy[4], v[4];

    for (int i = 0; i < 4; ++i)
        cin >> xy[i].fi >> xy[i].se;

    int res = 3;

    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j) {
            int f[2] = {0, 0};
            int sz = 0;
            for (int k = 0; k < 4; ++k) {
                if (k != i && k != j) {
                    f[sz] = k;
                    ++sz;
                }
            }
            for (int x1 = 1; x1 <= 20; ++x1)
                for (int y1 = 1; y1 <= 20; ++y1) {
                    pii p1 = mp(x1, y1);
                    if (p1 == xy[i] || p1 == xy[j])
                        continue;
                    for (int x2 = 1; x2 <= 20; ++x2)
                        for (int y2 = 1; y2 <= 20; ++y2) {
                            pii p2 = mp(x2, y2);
                            if (p2 == xy[i] || p2 == xy[j] || p2 == p1)
                                continue;
                            int cnt[4] = {0, 0, 0, 0};
                            //i, j
                            if (xy[i].fi == xy[j].fi || xy[i].se == xy[j].se) {
                                ++cnt[i];
                                ++cnt[j];
                            }
                            //i, f[0]
                            if (xy[i].fi == p1.fi || xy[i].se == p1.se) {
                                ++cnt[i];
                                ++cnt[f[0]];
                            }
                            //i, f[1]
                            if (xy[i].fi == p2.fi || xy[i].se == p2.se) {
                                ++cnt[i];
                                ++cnt[f[1]];
                            } 

                            //j, f[0]
                            if (xy[j].fi == p1.fi || xy[j].se == p1.se) {
                                ++cnt[j];
                                ++cnt[f[0]];
                            }
                            //j, f[1]
                            if (xy[j].fi == p2.fi || xy[j].se == p2.se) {
                                ++cnt[j];
                                ++cnt[f[1]];
                            }
                            //f[0], f[1]
                            if (p1.fi == p2.fi || p1.se == p2.se) {
                                ++cnt[f[0]];
                                ++cnt[f[1]];
                            }

                            int cur = (xy[f[0]] != p1) + (xy[f[1]] != p2);
                            if (cur < res && cnt[0] == 1 && cnt[1] == 1 && cnt[2] == 1 && cnt[3] == 1) {
                                res = cur;
                                v[i] = xy[i];
                                v[j] = xy[j];
                                v[f[0]] = p1;
                                v[f[1]] = p2;
                            }
                        }
                }
        }
    for (int i = 0; i < 4; ++i)
        cout << v[i].fi << ' ' << v[i].se << '\n';
}
