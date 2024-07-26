#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, S;
vector<int> vt;
map<int, int> totals;
long long res;

void left_side(int idx, int sum) {
    if (idx == N / 2) {
        res += totals[S - sum];
        return;
    }
    left_side(idx + 1, sum);
    left_side(idx + 1, sum + vt[idx]);
}

void right_side(int idx, int sum) {
    if (idx == N) {
        totals[sum]++;
        return;
    }
    right_side(idx + 1, sum);
    right_side(idx + 1, sum + vt[idx]);
}

int main() {
    cin >> N >> S;
    vt.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> vt[i];
    }

    right_side(N / 2, 0);
    left_side(0, 0);

    if (S == 0) {
        cout << res - 1 << "\n";
    } else {
        cout << res << "\n";
    }
}