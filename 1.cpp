#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 5) {
        cout << -1;
        return 0;
    }
    vector<int> p{2, 3};
    for (int i = 5; i < n; i += 2) {
        bool isP = true;
        for (auto pp : p) {
            if (i % pp == 0) {
                isP = false;
                break;
            }
        }
        if (isP) {
            p.push_back(i);
        }
    }

    for (int i = p.size() - 1; i > 0; i--) {
        if (p[i] == p[i - 1] + 2) {
            cout << 2 << ' ' << p[i - 1] << endl;
            return 0;
        }
    }
    return 0;
}
