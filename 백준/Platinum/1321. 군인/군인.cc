#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<long long> tree;

void update_tree(int crr, int bgn, int end, int idx, int diff) {
    if (end < idx || idx < bgn) return;
    if (bgn == end) {
        tree[crr] += diff;
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx, diff);
    update_tree(2 * crr + 1, mid + 1, end, idx, diff);
    tree[crr] = tree[2 * crr] + tree[2 * crr + 1];
}

long long query(int crr, int bgn, int end, int k) {
    if (bgn == end) return bgn;
    int mid = (bgn + end) / 2;
    if (tree[2 * crr] >= k) {
        return query(2 * crr, bgn, mid, k);
    } else {
        return query(2 * crr + 1, mid + 1, end, k - tree[2 * crr]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    tree.assign(4 * (N + 1), 0);
    for (int i = 0; i < N; i++) {
        int val;  cin >> val;
        update_tree(1, 0, N - 1, i, val);
    }
    cin >> M;
    while (M--) {
        int a;  cin >> a;
        if (a == 1) {
            int b, c;  cin >> b >> c;
            update_tree(1, 0, N - 1, b - 1, c);
        } else {
            int b;  cin >> b;
            cout << query(1, 0, N - 1, b) + 1 << "\n";
        }
    }
}
