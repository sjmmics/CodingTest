// 앞에 오는 큰 수 개수만큼 빈칸을 띄어서 배치
#include <iostream>
#include <vector>

using namespace std;

int N; 
vector<int> tree, res, mappings;

int query(int crr, int bgn, int end, int k) {
    if (bgn == end) {
        return crr;
    }
    int mid = (bgn + end) / 2;
    if (tree[2 * crr] >= k) {
        return query(2 * crr, bgn, mid, k);
    } else {
        return query(2 * crr + 1, mid + 1, end, k - tree[2 * crr]);
    }
}

void update_tree(int crr, int bgn, int end, int idx, int val) {
    if (end < idx || idx < bgn) return;
    if (bgn == end) {
        tree[crr] = val;
        if (val == 1) mappings[crr] = idx;
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
    res.assign(N, 0);
    tree.assign(4 * (N + 1), 0);
    mappings.assign(4 * (N + 1), 0);
    for (int i = 0; i < N; i++) {
        update_tree(1, 0, N - 1, i, 1);
    }
    for (int i = 1; i <= N; i++) {
        int k;  cin >> k;
        int tree_idx = query(1, 0, N - 1, k + 1);
        int vt_idx = mappings[tree_idx]; 
        update_tree(1, 0, N - 1, vt_idx, 0);
        res[vt_idx] = i;
    }
    
    for (int num : res) {
        cout << num << "\n";
    }
}