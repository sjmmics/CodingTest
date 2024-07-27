#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> vt;
vector<int> tree;

int query(int crr, int bgn, int end, int left, int right) {
    if (right < bgn || end < left) return 500'001;
    if (left <= bgn && end <= right) {
        return tree[crr];
    }
    int mid = (bgn + end) / 2;
    return min(query(2 * crr, bgn, mid, left, right),
            query(2 * crr + 1, mid + 1, end, left, right));
}

void update_tree(int crr, int bgn, int end, int idx, int val) {
    if (idx < bgn || end < idx) return;
    if (bgn == end) {
        tree[crr] = val;
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx, val);
    update_tree(2 * crr + 1, mid + 1, end, idx, val);
    tree[crr] = min(tree[2 * crr], tree[2 * crr + 1]);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vt.assign(N + 1, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= N; j++) {
            int x;  cin >> x;
            vt[x][i] = j;
        }
    }
    sort(vt.begin() + 1, vt.end());
    tree.assign(4 * (N + 1), 500'001);
    int res = 0;
    for (int i = 1; i <= N; i++) {
        int ret = query(1, 1, N, 1, vt[i][1]);
        if (ret > vt[i][2]) res++;
        update_tree(1, 1, N, vt[i][1], vt[i][2]);
    }
    cout << res << "\n";
}