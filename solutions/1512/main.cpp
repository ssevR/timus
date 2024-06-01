#pragma GCC optimize("O3")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define fi first
#define se second
 
 
const int MOD = 1e9+7; // 998244353; // = (119<<23)+1
const int MX = 2e5+5;
const int N = 1e5 + 5;
const ll INF = 1e18;
const ld PI = 4*atan((ld)1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
 
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
void solve(int n) {
    if (n % 2 == 0) {
        if (n % 6 != 2) {
            for (int j = 1; j <= n / 2; ++j)  {
                cout << j << ' ' << j * 2 << '\n';
                cout << n/2 + j << ' ' << 2 * j - 1 << '\n';
            }
        }
        else {
            for (int j = 1; j <= n / 2; ++j) {
                cout << j << ' ' << 1 + (2 * (j - 1) + n/2 - 1) % n << '\n';
                cout << n + 1 - j << ' ' << n - (2 * (j - 1) + n / 2 - 1) % n << '\n';
            }
        }
    }
    else {
        solve(n - 1);
        cout << n << ' ' << n << '\n';
    }

    return;
}

int main() {
    IOS;
    int n;
    cin >> n;
    solve(n);
}

