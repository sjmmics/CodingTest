#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, M;
vector<long long> tree;

void update_tree(int crr, int bgn, int end, int idx, int val) {
    if (idx < bgn || end < idx) return;
    if (bgn == end) {
        tree[crr] = val;
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx, val);
    update_tree(2 * crr + 1, mid + 1, end, idx, val);
    tree[crr] = max(tree[2 * crr], tree[2 * crr + 1]);
}

int get_bgst(int crr, int bgn, int end, int left, int right) {
    if (right < bgn || end < left) return 0;
    if (left <= bgn && end <= right) return tree[crr];
    int mid = (bgn + end) / 2;
    return max(get_bgst(2 * crr, bgn, mid, left, right), 
            get_bgst(2 * crr + 1, mid + 1, end, left, right));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    tree.resize(4 * (N + 1));
    for (int i = 0; i < N; i++) {
        int x;  cin >> x;
        update_tree(1, 0, N - 1, i, x);
    }
    for (int i = M - 1; i < N - M + 1; i++) {
        cout << get_bgst(1, 0, N - 1, i - (M - 1), i + M - 1) << "\n";
    }
}
