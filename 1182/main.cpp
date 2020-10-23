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
const int INF = 1e9;
const ld PI = 4*atan((ld)1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};


template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct node {
    int sz1;
    int sz2;
    vector<int> v1;
    vector<int> v2;
};

int const N = 202;
int g[N][N];
int used[N];
int n;
vector<node> w;
int knapsack[N][N];
int pr[N][N];

int dfs(int v, vector<int>& v1, vector<int>& v2) {
    if (used[v] == 1) {
        v1.push_back(v);
    }
    else {
        v2.push_back(v);
    }

    for (int i = 0; i < n; ++i) {
        if (g[v][i]) {
            if (used[v] == used[i]) {
                return 1;
            }
            if (used[i] == 0) {
                used[i] = 3 - used[v];
                if (dfs(i, v1, v2)) {
                    return 1;
                }
            }
        }
    }

    return 0;
}


int main() {
    IOS;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int cur;
        while(1) {
            cin >> cur;
            if (cur == 0) {
                break;
            }
            --cur;
            g[i][cur] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (g[i][j] && g[j][i]) {
                g[i][j] = -1;
                g[j][i] = -1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == -1) {
                g[i][j] = 0;
            }
            else if (i != j) {
                g[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            vector<int> v1, v2;
            used[i] = 1;
            if (dfs(i, v1, v2)) {
                cout << "No solution\n";
                return 0;
            }

            w.push_back({v1.size(), v2.size(), v1, v2});
        }
    }

    knapsack[0][0] = 1;

    for (int i = 0; i < w.size(); ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j >= w[i].sz1) {
                if (knapsack[i][j - w[i].sz1]) {
                    knapsack[i + 1][j] = 1;
                    pr[i + 1][j] = 0;
                }
            }
            if (j >= w[i].sz2) {
                if (knapsack[i][j - w[i].sz2]) {
                    knapsack[i + 1][j] = 1;
                    pr[i + 1][j] = 1;
                }
            }
        }
    }
    vector<int> v1, v2;

    for (int i = (n + 1) / 2; i >= 0; --i) {
        if (knapsack[w.size()][i]) {
            int cur = i;
            for (int j = w.size(); j > 0; --j) {
                if (pr[j][cur]) {
                    swap(w[j - 1].v1, w[j - 1].v2);
                }
                for(auto x : w[j - 1].v1) {
                    v1.push_back(x);
                }
                for (auto x : w[j - 1].v2) {
                    v2.push_back(x);
                }
                cur -= w[j - 1].v1.size();
            }
            assert(i != 0);
            assert(cur == 0);
            assert(i == v1.size());
            break;
        }
    }

    for (int i = 0; i < v1.size(); ++i) {
        for (int j = i + 1; j < v1.size(); ++j) {
            assert(g[v1[i]][v1[j]] == 0);
        }
    }

    for (int i = 0; i < v2.size(); ++i) {
        for (int j = i + 1; j < v2.size(); ++j) {
            assert(g[v2[i]][v2[j]] == 0);
        }
    }

    cout << v1.size() << ' ';
    for (auto x : v1) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
    cout << v2.size() << ' ';
    for (auto x : v2) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
    return 0;
}
