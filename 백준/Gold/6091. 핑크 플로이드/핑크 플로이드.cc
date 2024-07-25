#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> prnts;
vector<vector<int>> res;
vector<pair<int, pair<int, int>>> edges;
int N;

int get_prnt(int x) {
    if (prnts[x] == x) return x;
    prnts[x] = get_prnt(prnts[x]);
    return prnts[x];
}

bool equal_prnt(int x, int y) {
    x = get_prnt(x);
    y = get_prnt(y);
    return x == y;
}

void union_set(int x, int y) {
    x = get_prnt(x);
    y = get_prnt(y);
    if (x < y) {
        prnts[y] = x;
    } else {
        prnts[x] = y;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int cost;  cin >> cost;
            edges.push_back({ cost, { i, j }});
        }
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i <= N; i++) {
        prnts.push_back(i);
    }
    res.resize(N + 1);
    int cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (cnt == N - 1) break;
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;

        if (!equal_prnt(node1, node2)) {
            cnt++;
            union_set(node1, node2);
            res[node1].push_back(node2);
            res[node2].push_back(node1);
        }
    }

    for (int i = 1; i < res.size(); i++) {
        cout << res[i].size() << " ";
        sort(res[i].begin(), res[i].end());
        for (int num : res[i]) {
            cout << num << " ";
        }
        cout << "\n";
    }
}
