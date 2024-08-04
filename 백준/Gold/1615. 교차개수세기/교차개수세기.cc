#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
long long tree[4 * 2'001];
vector<vector<int>> vt;

void update_tree(int crr, int bgn, int end, int idx) {
    if (end < idx || idx < bgn) return;
    if (bgn == end) {
        tree[crr]++;
        return;
    }
    int mid = (bgn + end) / 2;
    update_tree(2 * crr, bgn, mid, idx);
    update_tree(2 * crr + 1, mid + 1, end, idx);
    tree[crr] = tree[2 * crr] + tree[2 * crr + 1];
}
long long query(int crr, int bgn, int end, int left, int right) {
    if (end < left || right < bgn) return 0;
    if (left <= bgn && end <= right) return tree[crr];
    int mid = (bgn + end) / 2;
    return query(2 * crr, bgn, mid, left, right) + 
            query(2 * crr + 1, mid + 1, end, left, right);
}

long long solution() {
    long long ret = 0;
    for (int i = 0; i < M; i++) {
        ret += query(1, 0, N - 1, vt[i][1] + 1, N - 1);
        update_tree(1, 0, N - 1, vt[i][1]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    vt.assign(M, vector<int>(2, 0));
    for (int i = 0; i < M; i++) {
        cin >> vt[i][0] >> vt[i][1];
        vt[i][0]--, vt[i][1]--;
    }
    sort(vt.begin(), vt.end());

    cout << solution() << "\n";
}