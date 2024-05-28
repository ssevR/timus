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
    IOS;

    char c[36];
    for (int i = 0; i < 10; ++i) {
        c[i] = i + '0';
    }
    for (int i = 10; i < 36; ++i) {
        c[i] = i - 10 + 'A';
    }

    while(true) {
        int a, b, k;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            return 0;
        }
        cin >> k;

        vector<int> int_part, fract_part;

        if (a >= b) {
            int f = a/b;
            while(f > 0) {
                int_part.push_back(f % k);
                f /= k;
            }
            reverse(int_part.begin(), int_part.end());
        }
        else {
            int_part.push_back(0);
        }

        a %= b;

        pii per = {-1, -1};

        if (a > 0) {
            map<int, int> mp;
            for (int i = 0; ;++i) {
                a *= k;
                if (mp.find(a) != mp.end()) {
                    per = {mp[a], i};
                    break;
                }
                mp[a] = i;
                fract_part.push_back(a / b);
                a %= b;

                if (a == 0) {
                    break;
                }
            }
        }

        for (int i = 0; i < int_part.size(); ++i) {
            cout << c[int_part[i]];
        }

        if (fract_part.empty()) {
            cout << '\n';
            continue;
        }

        cout << '.';
        for (int i = 0; i < fract_part.size(); ++i) {
            if (i == per.fi) {
                cout << '(';
            }
            cout << c[fract_part[i]];
        }
        if (per.se != -1) {
            cout << ')';
        }
        cout << '\n';
    }

}
