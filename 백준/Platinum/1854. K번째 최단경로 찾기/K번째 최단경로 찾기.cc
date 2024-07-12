#include <iostream>
#include <vector>
#include <queue>
#define MAX_NUM 1001

using namespace std;

int n, m, k;

vector<pair<int, int>> grp[MAX_NUM];
priority_queue<int> kth_que[MAX_NUM + 1];

void solve() {
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, 1 });
    kth_que[1].push(0);

    while (!pq.empty()) {
        int crr_cost = -pq.top().first;
        int crr_node = pq.top().second;
        pq.pop();

        for (int i = 0; i < grp[crr_node].size(); i++) {
            int nxt_cost = crr_cost + grp[crr_node][i].first;
            int nxt_node = grp[crr_node][i].second;

            if (kth_que[nxt_node].size() < k) {
                kth_que[nxt_node].push(nxt_cost);
                pq.push({ -nxt_cost, nxt_node });
            } else if (kth_que[nxt_node].top() > nxt_cost) {
                kth_que[nxt_node].pop();
                kth_que[nxt_node].push(nxt_cost);
                pq.push({ -nxt_cost, nxt_node });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        grp[a].push_back({ c, b });
    }

    solve();

    for (int i = 1; i <= n; i++) {
        if (kth_que[i].size() != k) {
            cout << -1 << "\n";
        } else {
            cout << kth_que[i].top() << "\n";
        }
    }
}
