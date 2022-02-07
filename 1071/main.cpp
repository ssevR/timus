#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int const MAX = 1e6 + 1;
int const MAX_L = 50; // log_2(1e6)

int dp[MAX_L][MAX_L];

vector<int> convert_to_base(int x, int base) {
    vector<int> res;
    while(x) {
        res.push_back(x % base);
        x /= base;
    }
    reverse(res.begin(), res.end());
    
    
    return res;
}

int main() {
    int x, y;
    cin >> x >> y;

    for (size_t i = 2; i < x + 2; ++i) {
        vector<int> vx = convert_to_base(x, i);
        vector<int> vy = convert_to_base(y, i);
        for (size_t j = 0; j < vx.size() + 1; ++j) {
            for (size_t k = 0; k < min(j, vy.size()) + 1; ++k) {
                dp[j][k] = 0;
                if (k == 0) {
                    dp[j][k] = 1;
                    continue;
                }

                for (int f = (int)j - 1; f >= 0; --f) {
                    if (vx[f] == vy[k - 1] && dp[f][k - 1]) {
                        dp[j][k] = 1;
                    }
                }
            }
        }
        if (dp[vx.size()][vy.size()] == 1) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "No solution\n";
    return 0;
}
