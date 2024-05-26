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
#define pb push_back


const int MOD = 1e9+7; // 998244353; // = (119<<23)+1
const int MX = 2e5+5;
const ll INF = 1e18;
const ld PI = 4*atan((ld)1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};


template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<int> > g;

pii solve(int v, int pr = -1) {
    pii res = {0, 0};

    for (auto u : g[v]) {
        if (u != pr && !solve(u, v).first) {
            res.first = 1;
            res.second = u;
            break;
        }
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    --k;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].pb(u);
        g[u].pb(v);
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }


    auto res = solve(k);
    if (res.fi == 0) {
        cout << "First player loses\n";
    }
    else {
        cout << "First player wins flying to airport " << res.se + 1 << '\n';
    }
}
