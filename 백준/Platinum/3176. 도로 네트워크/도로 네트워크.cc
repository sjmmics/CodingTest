#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX_NODE 100'000

using namespace std;

const int TH =  (int) floor(log2(MAX_NODE)) + 1;
int N, K;
vector<int> depths;
vector<bool> vstd;
vector<vector<int>> prnts, min_roads, max_roads;
vector<vector<pair<int, int>>> grp;

pair<int, int> solution(int x, int y) {
    if (depths[x] < depths[y]) swap(x, y);
    int diff = depths[x] - depths[y];
    int max_len = 0;
    int min_len = 1e9 + 7;
    for (int k = 0; diff > 0; k++) {
        if (diff % 2 == 1) {
            max_len = max(max_len, max_roads[x][k]);
            min_len = min(min_len, min_roads[x][k]);
            x = prnts[x][k];
        }
        diff = diff >> 1;
    }
    if (x == y) return make_pair(min_len, max_len);
    for (int k = TH; k >= 0; k--) {
        if (prnts[x][k] != prnts[y][k]) {
            max_len = max(max_len, max(max_roads[x][k], max_roads[y][k]));
            min_len = min(min_len, min(min_roads[x][k], min_roads[y][k]));
            x = prnts[x][k];
            y = prnts[y][k];
        }
    }
    max_len = max(max_len, max(max_roads[x][0], max_roads[y][0]));
    min_len = min(min_len, min(min_roads[x][0], min_roads[y][0]));

    return make_pair(min_len, max_len);
}

void set_dstc() {
    for (int k = 1; k < TH; k++) {
        for (int i = 1; i <= N; i++) {
            prnts[i][k] = prnts[ prnts[i][k - 1] ][k - 1];
            max_roads[i][k] = 
                max(max_roads[i][k - 1], max_roads[prnts[i][k - 1]][k - 1]);
            min_roads[i][k] = 
                min(min_roads[i][k - 1], min_roads[prnts[i][k - 1]][k - 1]);
        }
    }
}

void set_prnt(int crr, int depth) {
    vstd[crr] = true;
    depths[crr] = depth;
    
    for (pair<int, int> nxt : grp[crr]) {
        int nxt_node = nxt.first;
        int nxt_cost = nxt.second;
        if (vstd[nxt_node]) continue;
        prnts[nxt_node][0] = crr;
        max_roads[nxt_node][0] = min_roads[nxt_node][0] = nxt_cost;
        set_prnt(nxt_node, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    grp.resize(N + 1);
    vstd.assign(N + 1, false);
    depths.assign(N + 1, 0);
    prnts.assign(N + 1, vector<int>(TH, 0));
    max_roads.assign(N + 1, vector<int>(TH, 0));
    min_roads.assign(N + 1, vector<int>(TH, 0));
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;  cin >> a >> b >> c;
        grp[a].push_back({ b, c });
        grp[b].push_back({ a, c });
    }

    set_prnt(1, 0);

    set_dstc();

    cin >> K;
    for (int i = 0; i < K; i++) {
        int a, b;  cin >> a >> b;
        pair<int, int> res = solution(a, b);
        cout << res.first << " " << res.second << "\n";
    }
    
}