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

map<int, string> mp;

string solve(int n) {
    if (n == 1) return "";
    if (mp.count(n)) return mp[n];
    vector<string> v;
    for (int i = 2; i <= 9; ++i) {
        if (n % i == 0) {
            string cur = solve(n / i);
            if (cur != "-1") {
                cur += to_string(i);
            }
            sort(cur.begin(), cur.end());
            v.push_back(cur);
        }
    }
    if (v.empty()) {
        mp[n] = "-1";
        return "-1";
    }
    string mi = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i].size() < mi.size() || (v[i].size() == mi.size() && v[i] < mi))
            mi = v[i];
    }
    return mp[n] = mi;
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 10 << '\n';
        return 0;
    } else if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    string s = solve(n);
    cout << s << '\n';
}
