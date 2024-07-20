#include <iostream>
#include <vector>

using namespace std;

int T;
vector<long long> tree;
vector<int> arr;

long long query(int crr, int bgn, int end, int left, int right) {
    if (bgn > right || left > end) return 0;
    if (left <= bgn && end <= right) return tree[crr];
    int mid = (bgn + end) / 2;
    return query(2 * crr, bgn, mid, left, right) + 
            query(2 * crr + 1, mid + 1, end, left, right);
}

void update_tree(int crr, int bgn, int end, int idx, int diff) {
    if (bgn > idx || idx > end) return;
    tree[crr] += diff;
    if (bgn != end) {
        int mid = (bgn + end) / 2;
        update_tree(2 * crr, bgn, mid, idx, diff);
        update_tree(2 * crr + 1, mid + 1, end, idx, diff);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;  cin >> n >> m;
        tree = vector<long long>(4 * (n + m + 11));
        arr = vector<int>(n + m + 11);
        for (int i = m + 1; i <= n + m; i++) {
            update_tree(1, 1, n + m, i, 1);
        }
        for (int i = 1; i <= n; i++) {
            arr[i] = m + i;
        }

        int top_idx = m;
        for (int i = 0; i < m; i++) {
            int picked;  cin >> picked;
            cout << query(1, 1, n + m, 1, arr[picked] - 1) << " ";
            update_tree(1, 1, n + m, arr[picked], -1);
            arr[picked] = top_idx;
            top_idx--;
            update_tree(1, 1, n + m, arr[picked], 1);
        }
        cout << "\n";
    }
}