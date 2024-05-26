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
    ll k, l, n;
    cin >> k >> l >> n;

    ll win = min(k, n);
    ll lose = 0;
    ll draw = n - win;
    if (k - win == l - 1) {
        if (draw) {
            --draw;
            ++lose;
        }//-1
        else {
            --win;
            ++draw;
        }//-2
    }
    else if (k - win < l - 1) {
        if (draw) {
            --draw;
            ++lose;
        }//-1
        else {
            --win;
            ++lose;
        }//-3
    }

    cout << win * 3 + draw << ' ';

    lose = min(l, n);
    win = 0;
    draw = n - lose;

    if (l - lose == k - 1) {
        if (lose) {
            --lose;
            ++draw;
        }//+1
        else {
            --draw;
            ++win;
        } //+2
    }
    else if (l - lose == k - 2) {
        if (lose >= 2) {
            lose -= 2;
            draw += 2;
        }//+2
        else if (draw) {
            --draw;
            ++win;
        } //+2
        else {
            --lose;
            ++win;
        } //+3
    }
    else if (l - lose < k - 2) {
        if (draw) {
            --draw;
            ++win;
        }//+2
        else {
            --lose;
            ++win;
        }//+3
    }

    cout << win * 3 + draw << '\n';
}
