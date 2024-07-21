#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<long long> tree;

long long get_sum(int crr, int bgn, int end, int left, int right) {
    if (end < left || right < bgn) return 0; 
    if (left <= bgn && end <= right) return tree[crr];
    int mid = (bgn + end) / 2;
    return get_sum(2 * crr, bgn, mid, left, right) + 
            get_sum(2 * crr + 1, mid + 1, end, left, right);
}

void update_tree(int crr, int bgn, int end, int idx, int val) {
    if (end < idx || idx < bgn) return;
    if (bgn == end) {
        tree[crr] = val;
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx, val);
    update_tree(2 * crr + 1, mid + 1, end, idx, val);
    tree[crr] = tree[2 * crr] + tree[2 * crr + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    tree.resize(4 * (N + 10));
    while (M--) {
        int a, b, c;  cin >> a >> b >> c;
        if (a == 0) {
            if (b > c) swap(b, c);
            cout << get_sum(1, 1, N + 1, b, c) << "\n";
        } else {
            update_tree(1, 1, N + 1, b, c);
        }
    }
}