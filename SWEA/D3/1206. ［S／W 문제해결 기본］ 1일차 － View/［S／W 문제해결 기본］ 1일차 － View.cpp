#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int t = 1; t <= 10; t++) {
        cin >> N;
        vt.assign(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> vt[i];
        }
        int res = 0;
        for (int i = 2; i < N - 2; i++) {
            if (vt[i] > vt[i - 1] && vt[i] > vt[i - 2] 
                    && vt[i] > vt[i + 1] && vt[i] > vt[i + 2]) {
                int bgst = max(max(vt[i - 1], vt[i - 2]), max(vt[i + 1], vt[i + 2]));
                res += vt[i] - bgst;
            }
        }
        cout << "#" << t << " " << res << "\n";
    }
    return 0;
}