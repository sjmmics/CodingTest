#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
vector<int> tree;
int INF = pow(2, 31);

void update_tree(int crr, int bgn, int end, int idx, int val) {
    if (end < idx || idx < bgn) return;
    if (bgn == end) {
        tree[crr] = val;
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx, val);
    update_tree(2 * crr + 1, mid + 1, end, idx, val);
    tree[crr] = min(tree[2 * crr], tree[2 * crr + 1]);
}

int get_smst(int crr, int bgn, int end, int left, int right) {
    if (right < bgn || end < left) return INF;
    if (bgn == end) return tree[crr];
    if (left <= bgn && end <= right) return tree[crr];
    int mid = (bgn + end) / 2;
    return min(get_smst(2 * crr, bgn, mid, left, right), 
            get_smst(2 * crr + 1, mid + 1, end, left, right));
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    tree.resize(4 * (N + 10));
    for (int i = 0; i <= tree.size(); i++) {
        tree[i] = INF;
    }
    for (int i = 0; i < N; i++) {
        int x;  cin >> x;
        update_tree(1, 0, N - 1, i, x);
    }

    cin >> M;
    while (M--) {
        int a, b, c;  cin >> a >> b >> c;
        if (a == 1) {
            update_tree(1, 0, N - 1, b - 1, c);
        } else {
            cout << get_smst(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }
}