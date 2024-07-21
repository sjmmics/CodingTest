#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, res;
vector<pair<int, int>> vt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vt.resize(N);
    res;
    for (int i = 0; i < N; i++) {
        int x;  cin >> x;
        vt[i].first = x;
        vt[i].second = i;
    }
    sort(vt.begin(), vt.end());
    for (int i = 0; i < N; i++) {
        if (res < vt[i].second - i) {
            res = vt[i].second - i;
        }
    }
    cout << res + 1 << "\n";
}