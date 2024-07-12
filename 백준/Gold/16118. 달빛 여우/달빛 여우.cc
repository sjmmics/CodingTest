#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int N, M;
vector<vector<pair<int, int>>> grp;
int dstc_fox[4001];
int dstc_wolf[4001][2];


void fox() {
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, 1 });
    dstc_fox[1] = 0;

    while (!pq.empty()) {
        int crr_cost = -pq.top().first;
        int crr_node = pq.top().second;
        pq.pop();

        if (dstc_fox[crr_node] < crr_cost) {
            continue;
        }

        for (int i = 0; i < grp[crr_node].size(); i++) {
            int nxt_node = grp[crr_node][i].first;
            int nxt_cost = grp[crr_node][i].second + crr_cost;

            if (dstc_fox[nxt_node] > nxt_cost) {
                dstc_fox[nxt_node] = nxt_cost;
                pq.push({ -nxt_cost, nxt_node });
            }
        }
    }
}

void wolf() {

    // dstc, node, state(1 : 걷기, 2: 뛰기)
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({ 0, { 1, 1 }});

    while (!pq.empty()) {
        int crr_cost = -pq.top().first;
        int crr_node = pq.top().second.first;
        int crr_state = pq.top().second.second;
        pq.pop();

        if (dstc_wolf[crr_node][(crr_state + 1) % 2] < crr_cost) continue;

        for (int i = 0; i < grp[crr_node].size(); i++) {

            if (crr_state == 1) {
                int nxt_node = grp[crr_node][i].first;
                int nxt_cost = crr_cost + grp[crr_node][i].second / 2;

                if (dstc_wolf[nxt_node][1] > nxt_cost) {
                    dstc_wolf[nxt_node][1] = nxt_cost;
                    pq.push({ -nxt_cost, { nxt_node, 0}});
                }
            } else { // crr_state == 0
                int nxt_node = grp[crr_node][i].first;
                int nxt_cost = crr_cost + grp[crr_node][i].second * 2;

                    if (dstc_wolf[nxt_node][0] > nxt_cost) {
                    dstc_wolf[nxt_node][0] = nxt_cost;
                    pq.push({ -nxt_cost, { nxt_node, 1}});
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    grp.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        grp[u].push_back({ v, w * 2});
        grp[v].push_back({ u, w * 2});
    }

    for (int i = 1; i <= N; i++) {
        dstc_fox[i] = INF;
        dstc_wolf[i][0] = INF;
        dstc_wolf[i][1] = INF;
    }

    fox();
    wolf();

    int res = 0;
    for (int i = 2; i <= N; i++) {
        if (dstc_fox[i] < min(dstc_wolf[i][0] , dstc_wolf[i][1])) {
            res++;
        }
    }
    cout << res << "\n";
}