#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1 : a\n";
        return 0;
    }
    else if (n == 2) {
        cout << "1 : NO\n"
             << "2 : aa\n";

        return 0;
    }

    cout << "1 : NO\n"
         << "2 : NO\n";

    for (int i = 2; i < n; ++i) {
        cout << i + 1 << " : ";
        for (int j = 0; j < n - (i - 2); ++j) {
            cout << char('a' + (j % 3));
        }
        for (int j = n - (i - 2); j < n; ++j) {
            cout << 'd';
        }
        cout << '\n';
    }
    return 0;
}
