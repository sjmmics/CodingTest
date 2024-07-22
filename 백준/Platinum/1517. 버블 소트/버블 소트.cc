#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long res;
vector<pair<long long, int>> vt;
vector<int> tree;

void update_tree(int crr, int bgn, int end, int idx) {
    if (idx < bgn || end < idx) return;
    if (bgn == end) {
        tree[crr] = 1;
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx);
    update_tree(2 * crr + 1, mid + 1, end, idx);
    tree[crr] = tree[2 * crr] + tree[2 * crr + 1];
}

long long query(int crr, int bgn, int end, int left, int right) {
    if (end < left || right < bgn) return 0;
    if (left <= bgn && end <= right) {
        return tree[crr];
    }
    int mid = (bgn + end) / 2;
    return query(2 * crr, bgn, mid, left, right) + 
            query(2 * crr + 1, mid + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    tree.assign(4 * (N + 1), 0);
    vt.assign(N, { 0LL, 0 });
    for (int i = 0; i < N; i++) {
        cin >> vt[i].first;
        vt[i].second = i;
    }
    sort(vt.begin(), vt.end());
    for (int i = 0; i < N; i++) {
        int idx = vt[i].second;
        res += query(1, 0, N - 1, idx + 1, N - 1);
        update_tree(1, 0, N - 1, idx);
    }
    cout << res << "\n";
}
