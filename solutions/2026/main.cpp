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
 
 
int used[26];

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    queue<int> f[2];
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') {
            f[(i + 1) & 1].push(i);
        }
        else {
            used[s[i] - 'a'] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        cnt += used[i];
    }
    k -= cnt;
    if (k > (int)f[0].size() + (int)f[1].size()) {
        cout << "-1\n";
        return 0;
    }

    while(!f[0].empty() || !f[1].empty()) {
        int next[2] = {0, 25};

        if (k > 0) {
            while(used[next[0]]) {
                ++next[0];
            }
            while(used[next[1]]) {
                --next[1];
            }
        }
        if (!f[1].empty() && 25 - next[1] <= next[0]) {
            s[f[1].front()] = char('a' + next[1]);
            used[next[1]] = 1;
            f[1].pop();
        }
        else {
            s[f[0].front()] = char('a' + next[0]);
            used[next[0]] = 1;
            f[0].pop();
        }

        --k;
    }
    cout << s << '\n';
}
