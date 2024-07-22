#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
vector<int> tree;
vector<int> arr;

void update_tree(int crr, int bgn, int end, int idx) {
    if (end < idx || idx < bgn) return;
    if (bgn == end) {
        tree[crr] = idx;
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx);
    update_tree(2 * crr + 1, mid + 1, end, idx);
    if (arr[tree[2 * crr]] <= arr[tree[2 * crr + 1]]) {
        tree[crr] = tree[2 * crr];
    } else {
        tree[crr] = tree[2 * crr + 1];
    }
}

int query() {
    return tree[1] + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    arr.assign(N, 0);
    tree.assign(4 * (N + 1), 0);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < N; i++) {
        update_tree(1, 0, N - 1, i);
    }

    cin >> M;
    while (M--) {
        int a;  cin >> a;
        if (a == 1) {
            int b, c;  cin >> b >> c;
            b--;
            arr[b] = c;
            update_tree(1, 0, N - 1, b);
        } else {
            cout << query() << "\n";
        }
    }
}