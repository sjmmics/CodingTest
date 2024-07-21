#include<iostream>
#include<vector>

using namespace std;

int N, Q;
vector<long long> tree;

void update_tree(int crr, int bgn, int end, int idx, int val) {
    if (idx < bgn || end < idx) return;
    if (bgn == end) {
        tree[crr] += val;
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx, val);
    update_tree(2 * crr + 1, mid + 1, end, idx, val);
    tree[crr] = tree[2 * crr] + tree[2 * crr + 1];
}

long long query(int crr, int bgn, int end, int left, int right) {
    if (right < bgn || end < left) return 0;
    if (left <= bgn && end <= right) return tree[crr];
    int mid = (bgn + end) / 2;
    return query(2 * crr, bgn, mid, left, right) +
            query(2 * crr + 1, mid + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    tree.resize(4 * (N + 10));
    while (Q--) {
        int a, b, c;  cin >> a >> b >> c;
        if (a == 1) {
            update_tree(1, 0, N - 1, b - 1, c);
        } else {
            cout << query(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }
}