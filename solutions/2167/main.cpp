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
const int MX = 1048575 + 5;
const ll INF = 1e18;
const ld PI = 4*atan((ld)1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
 
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
bool is_prime[MX];

int main() {
    IOS;

    fill(is_prime, is_prime + MX, true);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MX; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int x = 0;
        while(!is_prime[n^x]) {
            ++x;
        }
        cout << x << '\n';
    }
}
