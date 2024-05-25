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
 
 
int solve(int n, int m) {
    if (n < m) {
        swap(n, m);
    }
    if (m <= 2) {
        return (n + 1) / 2;
    }
    if (n == 3 && m == 3) {
        return 2;
    }
    n %= 3;
    m %= 3;
    if (n == 0) {
        n += 3;
    }
    if (m == 0) {
        m += 3;
    }
    return solve(n, m);
}
int main() {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << '\n';
}
