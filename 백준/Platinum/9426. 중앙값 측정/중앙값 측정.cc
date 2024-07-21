#include <iostream>
#define RL 65550

using namespace std;

int arr[250001];
int tree[4 * (RL + 10)];
int N, K, M;
long long res;

void update_tree(int crr, int bgn, int end, int idx, int diff) {
    if (idx < bgn || end < idx) return;
    if (bgn == end) {
        tree[crr] += diff;
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx, diff);
    update_tree(2 * crr + 1, mid + 1, end, idx, diff);
    tree[crr] = tree[2 * crr] + tree[2 * crr + 1];
}

int query(int crr, int bgn, int end, int k) {
    if (bgn == end) return bgn;
    int mid = (bgn + end) / 2;
    if (tree[crr * 2] >= k) {
        return query(2 * crr, bgn, mid, k);
    } else {
        return query(2 * crr + 1, mid + 1, end, k - tree[2 * crr]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    M = ((K + 1) / 2);
    for (int i = 0; i < N; i++) {
        int x;  cin >> x;
        arr[i] = x;
    }
    for (int i = 0; i < K - 1; i++) {
        update_tree(1, 0, RL, arr[i], 1);
    }

    for (int i = K - 1; i < N; i++) {
        update_tree(1, 0, RL, arr[i], 1);
        res += query(1, 0, RL, M);
        update_tree(1, 0, RL, arr[i - K + 1], -1);
    }

    cout << res << "\n";
}
