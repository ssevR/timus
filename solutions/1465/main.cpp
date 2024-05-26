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

int mex(set<int> s) {
    for (int i = 0;;++i) {
        if (!s.count(i)) {
            return i;
        }
    }
}

int main() {
    int n = 200;
    vector<int> g(n + 1);
    g[0] = 0;
    g[1] = 1;
    g[2] = 1;

    for (int i = 3; i <= n; ++i) {
        set<int> cur;
        cur.insert(g[i - 2]);
        for (int j = 2; 2 * j <= i + 1; ++j) {
            cur.insert(g[i - j - 1] ^ g[j - 2]);
        }
        g[i] = mex(cur);
    }

    /*int last = 0;
    for (int i = 1; i <= n; ++i) {
        if (!g[i]) {
            cout << i - last << ' ' << i << '\n';
            last = i;
        }
    }*/

    int q;
    cin >> q;
    int res;

    if (q < 54) {
        res = g[q];
    }
    else {
        res = g[(q - 54) % 34 + 54];
    }

    if (res) {
        cout << "White\n";
    }
    else {
        cout << "Black\n";
    }

    return 0;
}
