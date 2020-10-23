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

vector<vector<int> > g;

int main() {
    IOS;
    vector<int> a;
    int cur;
    while(cin >> cur) {
        --cur;
        a.push_back(cur);
    }

    int n = a.size() + 1;
    g.resize(n);
    vector<int> d(n, 1);

    for (auto x : a) {
        ++d[x];
    }

    for (int i = 0; i < n - 1; ++i) {
        int v = 1e9;
        for (int j = 0; j < n; ++j) {
            if (d[j] == 1) {
                v = min(v, j);
            }
        }
        int u = a[i];
        g[v].push_back(u);
        g[u].push_back(v);
        --d[v];
        --d[u];
    }

    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ": ";
        sort(g[i].begin(), g[i].end());
        for (auto x : g[i]) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
}
