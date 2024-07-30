#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dstc[10'001];
int dpt[10'001][2];
bool vstd[10'001];
vector<int> route;
vector<vector<int>> grp;

void get_route(int crr, int prev) {
    
    if (dpt[crr][0] < dpt[crr][1] && !vstd[prev]) {
        route.push_back(crr);  
        vstd[crr] = true;
    }
    for (int nxt : grp[crr]) {
        if (nxt == prev) continue;
        get_route(nxt, crr);
    }
}

void dfs(int crr) {
    vstd[crr] = true;
    dpt[crr][0] = 0;
    dpt[crr][1] = dstc[crr];
    for (int nxt : grp[crr]) {
        if (vstd[nxt]) continue;
        dfs(nxt);
        dpt[crr][0] += max(dpt[nxt][0], dpt[nxt][1]);
        dpt[crr][1] += dpt[nxt][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dstc[i];
    }
    grp.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;  cin >> a >> b;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }
    dfs(1);
    for (int i = 0; i <= n; i++) {
        vstd[i] = false;
    }
    get_route(1, 0);
    sort(route.begin(), route.end());
    cout << max(dpt[1][0], dpt[1][1]) << "\n";
    for (int node : route) {
        cout << node << " ";
    } 
    cout << "\n";
}