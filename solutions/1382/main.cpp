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
const int N = 1000 + 3;
const ll INF = 1e18;
const ld PI = 4*atan((ld)1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
 
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 

int a[N], b[N], c[N];
int color[N];
int used1[N];
vector<int> wa[N];
vector<int> wb[N];

vector<vector<pii> > A, B;

int n;
vector<vector<int>> adj, adj_t;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;
int res[N];

void dfs1(int v) {
    used[v] = true;
    for (int u : adj[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : adj_t[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void add_disjunction(int a, bool na, int b, bool nb) {
    // na and nb signify whether a and b are to be negated
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}




int main() {
    IOS;
    fill(color, color + N, -1);

    int sz;
    cin >> sz;
    for (int i = 0; i < sz; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        --a[i], --b[i], --c[i];
    }

    for (int i = 0; i < sz; ++i) {
        if (used1[i]) {
            continue;
        }

        int cur = i;

        while(color[b[cur]] != i) {
            color[b[cur]] = i;
            cur = b[cur];
        }

        vector<pii> cur_a;
        vector<pii> cur_b;
        set<int> s_a;
        set<int> s_b;

        if (cur != i) {
            used1[i] = 1;
            cur_a.push_back({i, a[i]});
            s_a.insert(a[i]);

        }
        else {
            do {
                used1[cur] = 1;

                cur_a.push_back({cur, a[cur]});
                s_a.insert(a[cur]);
                cur_b.push_back({b[cur], c[cur]});
                s_b.insert(c[cur]);

                cur = b[cur];
            } while(cur != i);
        }
        if (cur_a.size() != s_a.size()) {
            cur_a.clear();
        }

        if (cur_b.size() != s_b.size()) {
            cur_b.clear();
        }

        A.push_back(cur_a);
        B.push_back(cur_b);
    }
    n = 2 * A.size();
    adj.resize(n);
    adj_t.resize(n);

    for (int i = 0; i < A.size(); ++i) {
        if (A[i].empty()) {
            add_disjunction(i, true, i, true);
        }
        else if (B[i].empty()) {
            add_disjunction(i, false, i, false);
        }
        for (auto x : A[i])
            wa[x.se].push_back(i);
        for (auto x : B[i])
            wb[x.se].push_back(i);

    }
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < wa[i].size(); ++j)
            for (int k = j + 1; k < wa[i].size(); ++k) {
                add_disjunction(wa[i][j], true, wa[i][k], true);
            }
        for (int j = 0; j < wb[i].size(); ++j)
            for (int k = j + 1; k < wb[i].size(); ++k) {
                add_disjunction(wb[i][j], false, wb[i][k], false);
            }
        for (int j = 0; j < wa[i].size(); ++j)
            for (int k = 0; k < wb[i].size(); ++k) {
                if (wa[i][j] != wb[i][k]) {
                    add_disjunction(wa[i][j], true, wb[i][k], false);
                }
            }
    }

    if (!solve_2SAT()) {
        return 1;
    }

    for (int i = 0; i < A.size(); ++i) {
        if (assignment[i]) {
            for (auto [ind, c] : A[i]) {
                res[ind] = 1;
            }
        }
        else {
            for (auto [ind, c] : B[i]) {
                res[ind] = 2;
            }
        }
    }
    for (int i = 0; i < sz; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}

