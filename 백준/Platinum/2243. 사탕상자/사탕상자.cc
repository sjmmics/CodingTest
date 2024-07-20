#include <iostream>
#include <vector>
#define MAX_SPAN 1'000'001

using namespace std;

int n;
int tree[4 * MAX_SPAN];
int arr[MAX_SPAN];

int query(int crr, int bgn, int end, int idx) {
    if (bgn == end) return bgn;
    int mid = (bgn + end) / 2;
    if (idx <= tree[2 * crr]) {
        return query(2 * crr, bgn, mid, idx);
    } else {
        return query(2 * crr + 1, mid + 1, end, idx - tree[2 * crr]);
    }
}

void update_tree(int crr, int bgn, int end, int idx, int val) {
    if (idx < bgn || end < idx) return;
    if (bgn == end) {
        tree[crr] += val;
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx, val);
    update_tree(2 * crr + 1, mid + 1, end, idx, val);
    tree[crr] = tree[2 * crr] + tree[2 * crr + 1];
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            int k = query(1, 1, MAX_SPAN, b);
            cout << k << "\n";
            update_tree(1, 1, MAX_SPAN, k, -1);
        } else {
            cin >> b >> c;
            update_tree(1, 1, MAX_SPAN, b, c);
        }
    }
}