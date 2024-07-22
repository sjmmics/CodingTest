#include <iostream>

#define SPAN 2'000'010

using namespace std;

int N;
int tree[4 * SPAN];

void update_data(int crr, int bgn, int end, int idx, int diff) {
    if (end < idx || idx < bgn) return; 
    if (bgn == end) {
        tree[crr] += diff;
        return;
    }
    int mid = (bgn + end) / 2;
    update_data(2 * crr, bgn, mid, idx, diff);
    update_data(2 * crr + 1, mid + 1, end, idx, diff);
    tree[crr] = tree[2 * crr] + tree[2 * crr + 1];
}

int get_data(int crr, int bgn, int end, int k) {
    if (bgn == end) {
        return bgn;
    }
    int mid = (bgn + end) / 2;
    if (tree[2 * crr] >= k) {
        return get_data(2 * crr, bgn, mid, k);
    } else {
        return get_data(2 * crr + 1, mid + 1, end, k - tree[2 * crr]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--) {
        int T, X;  cin >> T >> X;
        if (T == 1) {
            update_data(1, 1, SPAN, X, 1);
        } else {
            int del_val = get_data(1, 1, SPAN, X);
            cout << del_val << "\n";
            update_data(1, 1, SPAN, del_val, -1);
        }
    }
}