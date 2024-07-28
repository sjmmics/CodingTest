#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<pair<int, pair<int, int>>> edges;
int prnts[1'001];

int get_prnt(int x) {
    if (prnts[x] == x) {
        return x;
    }
    prnts[x] = get_prnt(prnts[x]);
    return prnts[x];
}

bool is_same_prnt(int x, int y) {
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

int solution() {
    for (int i = 0; i <= n; i++) {
        prnts[i] = i;
    }
    int ret = 0;
    for (pair<int, pair<int, int>> p : edges) {
        int node1 = p.second.first;
        int node2 = p.second.second;
        int cost = p.first;
        if (!is_same_prnt(node1, node2)) {
            union_set(node1, node2);
            ret += cost;
        }
    }
    return ret;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) break;
        edges.clear();
        for (int i = 0; i < m; i++) {
            char a;
            int b, c;
            cin >> a >> b >> c;
            if (a == 'B') {
                edges.push_back({ 1, { b, c }});
            } else {
                edges.push_back({ 0, { b, c }});
            }
        }
        sort(edges.begin(), edges.end());
        int smst = solution();
        sort(edges.begin(), edges.end(), greater<>());
        int bgst = solution();
        if (smst <= k && k <= bgst) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}