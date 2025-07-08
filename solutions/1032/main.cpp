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
    fastIO();
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> pr(n + 1);
    vector<int> ind(n, -2);
    ind[0] = -1;

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pr[i + 1] = a[i] + pr[i];
        if (ind[pr[i + 1] % n] != -2) {
            int l = ind[pr[i + 1] % n];
            for (int j = l + 1; j <= i; ++j) res.push_back(a[j]);
            break;
        }
        ind[pr[i + 1] % n] = i;
    }
    cout << res.size() << '\n';
    for (auto x : res) cout << x << '\n';
}
