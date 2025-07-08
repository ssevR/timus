#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

const int N = 2e5 + 10;
const ll LINF = 1e18;
const int INF = 1e9;
const ld PI = 4 * atanl(1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;
    ll res = 0;
    if (n < 1) {
        for (int i = n; i <= 1; ++i) res += i;
    } else {
        for (int i = 1; i <= n; ++i) res += i;
    }
    cout << res << '\n';
}
