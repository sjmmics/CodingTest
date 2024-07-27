#include <iostream>
#include <vector>

using namespace std;

typedef struct node_data {
    int min_val;
    int max_val;
    node_data(int A, int B) : 
        min_val(A), max_val(B) {}
} node_data;

int T, N, K;
vector<node_data> tree;
vector<int> vt;

node_data get_info(int crr, int bgn, int end, int left, int right) {
    if (end < left || right < bgn) return node_data(100'001, -1);
    if (left <= bgn && end <= right) {
        return tree[crr];
    }
    int mid = (bgn + end) / 2;
    node_data low_node_data = get_info(2 * crr, bgn, mid, left, right);
    node_data high_node_data = get_info(2 * crr + 1, mid + 1, end, left, right);
    int ret_min = min(low_node_data.min_val,  high_node_data.min_val);
    int ret_max = max(low_node_data.max_val,  high_node_data.max_val);
    return node_data(ret_min, ret_max);
}

bool query(int crr, int bgn, int end, int left, int right) {
    node_data section = get_info(crr, bgn, end, left, right);
    if (section.min_val != left) return false;
    if (section.max_val != right) return false;
    return true;
}

void update_tree(int crr, int bgn, int end, int idx, int val) {
    if (end < idx || idx < bgn) return;
    if (bgn == end) {
        tree[crr] = node_data(val, val);
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx, val);
    update_tree(2 * crr + 1, mid + 1, end, idx, val);
    int smst = min(tree[2 * crr].min_val, tree[2 * crr + 1].min_val);
    int bgst = max(tree[2 * crr].max_val, tree[2 * crr + 1].max_val);
    tree[crr] = node_data(smst, bgst);
}

void init_tree(int crr, int bgn, int end) {
    if (bgn == end) {
        tree[crr] = node_data(bgn, bgn);
        return;
    }
    int mid = (bgn + end) / 2;
    init_tree(2 * crr, bgn, mid);
    init_tree(2 * crr + 1, mid + 1, end);
    int smst = min(tree[2 * crr].min_val, tree[2 * crr + 1].min_val);
    int bgst = max(tree[2 * crr].max_val, tree[2 * crr + 1].max_val);
    tree[crr] = node_data(smst, bgst);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> K;
        tree.assign(4 * (N + 1), node_data(0, 0));
        vt.assign(N, 0);
        for (int i = 0; i < N; i++) {
            vt[i] = i;
        }
        init_tree(1, 0, N - 1);
        for (int i = 0; i < K; i++) {
            int q, a, b;  cin >> q >> a >> b;
            if (q == 0) {
                int val_a = vt[a];
                int val_b = vt[b];
                update_tree(1, 0, N - 1, a, val_b);
                update_tree(1, 0, N - 1, b, val_a);
                vt[a] = val_b;
                vt[b] = val_a;
            } else {
                bool res = query(1, 0, N - 1, a, b);
                if (res) cout << "YES" << "\n";
                else cout << "NO" << "\n";
            }
        }
    }
}