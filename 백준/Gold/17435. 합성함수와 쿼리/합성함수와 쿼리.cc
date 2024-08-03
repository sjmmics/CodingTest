#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 500'001;
const int CEIL = (int) (floor(log2(MAX)) + 1);

int m;
vector<vector<int>> vt;

void set_vt() {
    for (int j = 1; j < CEIL; j++) {
        for (int i = 1; i <= m; i++) {
            vt[i][j] = vt[ vt[i][j - 1] ][j - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m;
    vt.assign(MAX, vector<int>(CEIL, 0));
    for (int i = 1; i <= m; i++) {
        cin >> vt[i][0];
    }
    set_vt();
    int Q;  cin >> Q;
    for (int q = 0; q < Q; q++) {
        int n, x;  cin >> n >> x;
        for (int i = CEIL - 1; i >= 0; i--) {
            if (n & (1 << i)) {
                x = vt[x][i];
            }
        }
        cout << x << "\n";
    }
}