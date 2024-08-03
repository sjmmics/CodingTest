#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K;
int arr[100'001];
vector<int> tree;

void init_tree(int crr, int bgn, int end, int left, int right) {
    if (right < bgn || end < left) return;
    if (bgn == end) {
        if (arr[bgn] > 0) {
            tree[crr] = 1;
        } else if (arr[bgn] < 0) {
            tree[crr] = -1;
        } else {
            tree[crr] = 0;
        }
        return;
    }
    int mid = (bgn + end) / 2;
    init_tree(2 * crr, bgn, mid, left, right);
    init_tree(2 * crr + 1, mid + 1, end, left, right);
    tree[crr] = tree[2 * crr] * tree[2 * crr + 1];
}

void update_tree(int crr, int bgn, int end, int idx, int val) {
    if (idx < bgn || end < idx) return;
    if (bgn == end) {
        if (val > 0) {
            tree[crr] = 1;
        } else if (val < 0) {
            tree[crr] = -1;
        } else {
            tree[crr] = 0;
        }
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx, val);
    update_tree(2 * crr + 1, mid + 1, end, idx, val);
    tree[crr] = tree[2 * crr] * tree[2 * crr + 1];
}

int query(int crr, int bgn, int end, int left, int right) {
    if (right < bgn || end < left) return 1;
    if (left <= bgn && end <= right) return tree[crr];
    int mid = (bgn + end) / 2;
    return query(2 * crr, bgn, mid, left, right) * 
            query(2 * crr + 1, mid + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N >> K) {
        string answer = "";
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        tree.assign(4 * (N + 1), 0);
        init_tree(1, 0, N - 1, 0, N - 1);
        for (int i = 0; i < K; i++) {
            char x;  cin >> x;
            if (x == 'C') {
                int idx, val;  cin >> idx >> val;
                update_tree(1, 0, N - 1, idx - 1, val);
            } else {
                int l, r;  cin >> l >> r;
                int res = query(1, 0, N - 1, l - 1, r - 1);
                if (res > 0) {
                    answer += "+";
                } else if (res < 0) {
                    answer += "-";
                } else {
                    answer += "0";
                }
            }
        }
        cout << answer << "\n";
    }
}