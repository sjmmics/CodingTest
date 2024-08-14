#include <iostream>
#include <algorithm>
#define MAX 10'001
#define INF 987654321

using namespace std;

int N, node_idx, root_node;
int nodes[MAX], lows[MAX], highs[MAX];
pair<int, int> tree[MAX];

void dfs(int crr_node, int cnt) {
    if (tree[crr_node].first > 0) {
        dfs(tree[crr_node].first, cnt + 1);
    }

    lows[cnt] = min(lows[cnt], node_idx);
    highs[cnt] = max(highs[cnt], node_idx);
    node_idx++;

    if (tree[crr_node].second > 0) {
        dfs(tree[crr_node].second, cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < MAX; i++) {
        lows[i] = INF;
    }
    for (int i = 0; i < N; i++) {
        int prnt, left, right;
        cin >> prnt >> left >> right;
        
        nodes[prnt]++;
        tree[prnt].first = left;
        tree[prnt].second = right;

        if (left != -1) {
            nodes[left]++;
        }
        if (right != -1) {
            nodes[right]++;    
        }
    }
    for (int i = 0; i <= N; i++) {
        if (nodes[i] == 1) {
            root_node = i;
        }
    }

    node_idx = 1;
    dfs(root_node, 1);

    int res = highs[1] - lows[1] + 1;
    int depth = 1;
    for (int i = 2; i <= N; i++) {
        int temp = highs[i] - lows[i] + 1;
        if (temp > res) {
            res = temp;
            depth = i;
        }
    }
    cout << depth << " " << res << "\n";
}