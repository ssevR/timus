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
 
const int F = 15; 
int g[F][F];
int kx[4] = {1, -1, -1, 1} , ky[4] = {1, 1, -1, -1};
int n, a, b;

void dfs(int x, int y, int c) {
    g[x][y] = c;

    int tox;
    int toy;
    for (int i = 0; i < 4; ++i) {
        tox = x + kx[i] * a;
        toy = y + ky[i] * b;
        if (0 <= tox && tox < n && 0 <= toy && toy < n && !g[tox][toy]) {
            dfs(tox, toy, c);
        }
    }

    for (int i = 0; i < 4; ++i) {
        tox = x + kx[i] * b;
        toy = y + ky[i] * a;
        if (0 <= tox && tox < n && 0 <= toy && toy < n && !g[tox][toy]) {
            dfs(tox, toy, c);
        }
    }
}

int main() {
    cin >> n >> a >> b;
    if (n <= F) {
        int c = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 0) {
                    dfs(i, j, ++c);
                }
            }
        }
        cout << c << '\n';
        return 0;
    }
    if (a < b) {
        swap(a, b);
    }

    if (a == 0 && b == 0) {
        cout << 1ll * n * n << '\n';
    }
    else if (b == 0) {
        cout << a * a << '\n';
    }
    else if (a == 2 && b == 1) {
        cout << 1 << '\n';
    }
    else if (b == 1) {
        cout << 2 << '\n';
    }
    else if (a == 2 && b == 2) {
        cout << 8 << '\n';
    }
    else if (a == 3 && b == 2) {
        cout << 1 << '\n';
    }
    else if (a == 3 && b == 3) {
        cout << 18 << '\n';
    }
}
