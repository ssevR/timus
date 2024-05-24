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
    vector<int> res;
    res.push_back(n + 1);
    res.push_back(n - 1);
    int sz = 1;
    while(sz < n) {
        res.push_back(n - sz - 1);
        ++sz;
        if (sz == n) {
            break;
        }

        for (int i = n - sz + 2; i < n + sz + 1; i += 2) {
            res.push_back(i);
        }
        res.push_back(n + sz + 1);
        for (int i = n + sz - 1; i >= n - sz - 1; i -= 2) {
            res.push_back(i);
        }
        ++sz;
    }

    int shift = 0;
    while(n > 0) {
        if (n == 1) {
            res.push_back(shift + 1);
            break;
        }

        if (n % 2 == 1) {
            for (int i = 1; i <= 2 * n - 1; i += 2) {
                res.push_back(shift + i);
            }
            for (int i = 2 * n - 2; i >= 2; i -= 2) {
                res.push_back(shift + i);
            }
            res.push_back(shift + 3);
            n -= 3;
            shift += 3;
        }
        else {
            for (int i = 2; i <= 2 * n; i += 2) {
                res.push_back(shift + i);
            }
            for (int i = 2 * n - 1; i >= 1; i -= 2) {
                res.push_back(shift + i);
            }
            n -= 1;
            shift += 1;
        }
    }
    cout << res.size() << '\n';
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
