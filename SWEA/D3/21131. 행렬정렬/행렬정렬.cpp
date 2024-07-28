#include <iostream>
#include <vector>

using namespace std;

int T, N;
vector<vector<int>> vt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        vt.assign(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> vt[i][j];
            }
        }
        int res = 0;
        if (vt[0][1] != 0 * N + (1 + 1)) {
            res++;
        }
        for (int i = N - 2; i >= 1; i--) {
            int j = i + 1;
            if (vt[i][j] != i * N + (j + 1)) {
                res++;
                if (vt[i - 1][j - 1] != (i - 1) * N + (j - 1 + 1)) {
                    res--;
                } else {
                    res ++;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}