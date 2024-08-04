#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int N, P, K;
int dstc[1'001];
vector<pair<int, int>> grp[10'001];

struct comp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

void bfs(int price_limit) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> que;
    que.push({ 1, 0 });
    for (int i = 1; i <= N; i++) {
        dstc[i] = INF;
    }
    dstc[1] = 0;
    while (!que.empty()) {
        int crr_node = que.top().first;
        int crr_cost = que.top().second;
        que.pop();
        if (crr_cost < dstc[crr_node]) continue;
        for (int i = 0; i < grp[crr_node].size(); i++) {
            int nxt_node = grp[crr_node][i].first;
            int nxt_cost = grp[crr_node][i].second;
            if (nxt_cost > price_limit) {
                nxt_cost = 1;
            } else {
                nxt_cost = 0;
            }
            if (dstc[nxt_node] > crr_cost + nxt_cost) {
                dstc[nxt_node] = crr_cost + nxt_cost;
                que.push({ nxt_node, dstc[nxt_node] });
            }
        }
    }
}

int solution() {
    int ret = -1;
    int low = 0;
    int high = 1'000'000;
    while (low <= high) {
        int mid = (low + high) / 2;
        bfs(mid);
        if (dstc[N] <= K) {
            ret = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> P >> K;
    for (int i = 0; i < P; i++) {
        int a, b, c;  cin >> a >> b >> c;
        grp[a].push_back({ b, c });
        grp[b].push_back({ a, c });
    }
    cout << solution() << "\n";
}