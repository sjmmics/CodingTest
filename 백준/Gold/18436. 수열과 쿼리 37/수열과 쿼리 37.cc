#include <iostream>
#include <vector>

using namespace std;

int N, M; 
vector<int> vt, tree;

int query(int crr, int bgn, int end, int left, int right) {
    if (end < left || right < bgn) return 0;
    if (left <= bgn && end <= right) return tree[crr];
    int mid = (bgn + end) / 2;
    return query(2 * crr, bgn, mid, left, right) + 
            query(2 * crr + 1, mid + 1, end, left, right);
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

    cin >> N;
    vt.assign(N, 0);
    tree.assign(4 * (N + 1), 0);
    for (int i = 0; i < N; i++) {
        cin >> vt[i];
        if (vt[i] % 2 == 1) {
            update_tree(1, 0, N - 1, i, 1);
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;  cin >> a >> b >> c;
        
        if (a == 1) {
            b--;
            if (c % 2 == 1) {
                update_tree(1, 0, N - 1, b, 1);
            } else {
                update_tree(1, 0, N - 1, b, 0);
            }
        } else if (a == 2) {
            b--;  c--;
            int res = query(1, 0, N - 1, b, c);
            cout << (c - b + 1) - res << "\n";
        } else {
            b--;  c--;
            int res = query(1, 0, N - 1, b, c);
            cout << res << "\n";
        }
    }
}