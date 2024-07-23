#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> tree;

pair<int, int> get_bgst(const pair<int, int> &left, const pair<int, int> &right) {
    if (left.first >= right.first) {
        return { left.first, max(left.second, right.first) };
    } else {
        return { right.first, max(right.second, left.first) };
    }
}

void update_tree(int crr, int bgn, int end, int idx, int val) {
    if (end < idx || idx < bgn) return;
    if (bgn == end) {
        tree[crr] = { val, 0 };
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx, val);
    update_tree(2 * crr + 1, mid + 1, end, idx, val);
    tree[crr] = get_bgst(tree[2 * crr], tree[2 * crr + 1]);
}

pair<int, int> query (int crr, int bgn, int end, int left, int right) {
    if (end < left || right < bgn) return { 0, 0 };
    if (left <= bgn && end <= right) return tree[crr];
    int mid = (bgn + end) / 2;
    return get_bgst(query(2 * crr, bgn, mid, left, right), 
                query(2 * crr + 1, mid + 1, end, left, right));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    tree.assign(4 * (N + 1), { 0, 0 });
    for (int i = 0; i < N; i++) {
        int val;  cin >> val;
        update_tree(1, 0, N - 1, i, val);
    }
    cin >> M;
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update_tree(1, 0, N - 1, b - 1, c);
        } else {
            pair<int, int> ans = query(1, 0, N - 1, b - 1, c - 1);
            cout << (long long) ans.first + ans.second << "\n";
        }
    }
}