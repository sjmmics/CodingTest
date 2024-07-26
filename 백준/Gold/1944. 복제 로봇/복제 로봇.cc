#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int DX[4] = { 1, -1, 0, 0 };
int DY[4] = { 0, 0, 1, -1 };
int N, M;
char map[50][50];
vector<int> prnts;
vector<vector<int>> vstd;
vector<pair<int, pair<int, int>>> edges;
vector<pair<int, int>> nodes;

int get_prnt(int a) {
    if (a == prnts[a]) {
        return a;
    } else {
        prnts[a] = get_prnt(prnts[a]);
        return prnts[a];
    }
}

bool is_union_set(int a, int b) {
    a = get_prnt(a);
    b = get_prnt(b);
    return a == b;
}

void union_set(int a, int b) {
    a = get_prnt(a);
    b = get_prnt(b);
    prnts[b] = a;
}

int solution() {
    int res = 0;
    sort(edges.begin(), edges.end());
    prnts.assign(M + 2, 0);
    for (int i = 0; i <= M + 1; i++) {
        prnts[i] = i;
    }
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;
        if (!is_union_set(node1, node2)) {
            union_set(node1, node2);
            res += cost;
        }
    }
    return res;
}

void bfs(int sr, int sc) {
    queue<pair<int, int>> que;
    que.push({ sr, sc });
    vstd[sr][sc] = 0;
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if (nx < 0 || N <= nx || ny < 0 || N <= ny) {
                continue;
            }
            if (map[nx][ny] == '1') continue;
            if (vstd[nx][ny] != -1) continue;
            vstd[nx][ny] = vstd[x][y] + 1;
            que.push({ nx, ny });
        }
    }
}

bool set_edges() {
    for (int i = 1; i <= M + 1; i++) {
        vstd.assign(N, vector<int>(N, -1));
        int bgn_row = nodes[i].first;
        int bgn_col = nodes[i].second;
        bfs(bgn_row, bgn_col);
        for (int j = i + 1; j <= M + 1; j++) {
            int goal_row = nodes[j].first;
            int goal_col = nodes[j].second;
            if (vstd[goal_row][goal_col] == -1) {
                return false;
            }
            edges.push_back({vstd[goal_row][goal_col], { i, j }});
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    nodes.push_back({ -1, -1 });
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S' || map[i][j] == 'K') {
                nodes.push_back({ i, j });
            }
        }
    }
    if (!set_edges()) {
        cout << -1 << "\n";
        return 0;
    }

    cout << solution() << "\n";
}