#include <iostream>
#include <vector>
#define TH 20

using namespace std;

int N, M;
vector<vector<pair<int, int>>> grp;
int depths[40001];
int prnts[40001][TH];
int dstcs[40001][TH];
bool vstds[40001];

void set_prnt(int crr, int depth) {
    vstds[crr] = true;
    depths[crr] = depth;

    for (int i = 0; i < grp[crr].size(); i++) {
        int nxt = grp[crr][i].first;
        int cost = grp[crr][i].second;
        if (vstds[nxt]) continue;

        prnts[nxt][0] = crr;
        dstcs[nxt][0] = cost;
        set_prnt(nxt, depth + 1);
    }
}

int find_dstc(int x, int y) {
    int sum = 0;
    if (depths[x] < depths[y]) swap(x, y);

    for (int k = TH - 1; k >= 0; k--) {
        int diff = depths[x] - depths[y];
        if (diff >= (1 << k)) {
            sum += dstcs[x][k];
            x = prnts[x][k];
        }
    }

    if (x == y) return sum;

    for (int k = TH - 1; k >= 0; k--) {
        if (prnts[x][k] == prnts[y][k]) {
            continue;
        }
        sum += (dstcs[x][k] + dstcs[y][k]);
        x = prnts[x][k];
        y = prnts[y][k];
    }
    return sum + dstcs[x][0] + dstcs[y][0];
}

int main() {
    cin >> N;
    grp = vector<vector<pair<int, int>>>(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        grp[a].push_back({ b, c });
        grp[b].push_back({ a, c });
    }

    set_prnt(1, 0);

    for (int k = 1; k < TH; k++) {
        for (int i = 1; i <= N; i++) {
            prnts[i][k] = prnts[ prnts[i][k - 1] ][k - 1];
            if (prnts[ prnts[i][k - 1] ][k - 1] == 0) {
                continue;
            }    
            dstcs[i][k] = dstcs[i][k - 1] + dstcs[ prnts[i][k - 1] ][k - 1];
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        int d, e;
        cin >> d >> e;
        cout << find_dstc(d, e) << "\n";
    }
}